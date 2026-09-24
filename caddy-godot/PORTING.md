# CaddySmash — Unreal → Godot port

Source of truth for the original behaviour is `../Source/CaddySmash/`.

## Run

- Play: main scene is `scenes/test_track.tscn`.
- Verify physics headlessly:

```bash
godot --headless --path caddy-godot res://tests/movement_check.tscn
```

`movement_check` asserts the ported car reproduces the Unreal tuning: top speed,
0→20 time, drift/grip steering rates, lateral friction retention, reverse
steering hysteresis, control lock, arcade wall glide, every brake-dash phase
transition, impact tiers and damage, and the knockback/stagger reactions. It
exits non-zero on failure. Pass `-- --verbose-checks` to log each check to
`user://check_progress.log` as it starts, which is how you locate a hang —
Godot's stdout is block-buffered when piped, so `print` shows nothing until exit.

**If a headless run hangs at idle memory with no output, the `.godot` cache is
missing or broken.** Without it `class_name` types do not resolve, and the
runtime sits in its main loop forever instead of reporting anything. Rebuild it:

```bash
godot --headless --editor --quit --path caddy-godot
```

## Controls

The game boots into the join screen (`scenes/join_screen.tscn`). Up to four
players claim a seat, one per device, then any of them starts the match.

| | Keyboard | Gamepad |
|---|---|---|
| Join / leave a seat | Enter / Esc | A / B |
| Start the match | Space | START |
| Move intent (aim) | WASD | Left stick |
| Accelerate | Shift | RT, A |
| Brake / reverse | Q | LT, B |
| Brake-dash (hold to charge, release to fire) | Space | X |
| Grip (tuning aid) | Ctrl | LB |
| Debug menu | F1 | |
| Next / previous handling preset | F2 / F3 | |
| Respawn all cars | R | |

## Handling presets

Port of the runtime tuning presets on `ACaddyVehiclePawn`, which Unreal cycled
through `caddy.vehicle.tuning.next` / `.prev` / `.set`. Bound to **F2/F3** here,
with the active preset shown bottom-right.

Five presets in `resources/tuning/presets/`, ordered snappiest to heaviest. **Top
speed is held at 22 m/s across all of them** so the only variable is how long the
car takes to get there; brake and coast scale with acceleration so momentum keeps
a consistent weight.

| preset | accel | distance to HIGH momentum |
|---|---|---|
| Stock | 62 (6.3 g) | 3.2 m |
| Quick | 45 (4.6 g) | 4.2 m |
| Balanced | 32 (3.3 g) | 6.2 m |
| Weighty | 24 (2.4 g) | 8.4 m |
| Heavy | 18 (1.8 g) | 11.7 m |

Distance-to-HIGH is the number that matters: below it a car cannot win a contest.
The arena is 38 m across, so Stock reaches top tier in 8% of it — which is why
almost every fight resolved as a CLASH and the momentum rule rarely decided
anything. Regenerate the table after any change with
`res://tests/acceleration_probe.tscn`.

The switcher applies the preset to **every** car, since comparing feel only means
something if both sides of a fight are on the same numbers. The debug menu
rebinds its Handling tab when a preset changes, or it would go on editing a
resource no car is using.

## Local multiplayer

`scripts/input/input_device.gd` polls one keyboard or one gamepad **directly** —
`Input.get_joy_axis(device_id, ...)`, `Input.is_physical_key_pressed(...)`.

This replaced the InputMap for gameplay, and it had to. InputMap actions
aggregate every connected device: `Input.get_action_strength("caddy_accelerate")`
is true when *any* pad pulls a trigger, so there is no way to ask what player 2
is doing. The InputMap now only carries `caddy_debug_toggle` and `caddy_reset`,
where aggregation is the behaviour you want.

The join screen writes to the `PlayerRoster` autoload, which survives the scene
change into `scenes/arena_match.tscn`. `MatchManager` reads the roster, spawns a
car per seat at the arena's spawn ring, assigns each driver its device, and tints
the body with the seat colour. Running `arena_match.tscn` directly still works:
an empty roster falls back to a single keyboard player.

**One shared camera, not split screen**, and in the match it is fixed rather than
chasing: `center_bias = 1` locks the shot to the arena centre, `base_pitch_deg =
-85` makes it near top-down, and `fit_ground_radius` solves the arm length so the
whole arena sits in the vertical FOV. In that mode the speed and spread offsets
and the look-ahead are all suppressed on purpose — every one of them makes the
frame breathe, which is the opposite of a steady shot.

Because the framing is solved from `fit_ground_radius`, **how big the cars look
is set by the arena size**. Shrink `Arena.radius` and drop `fit_ground_radius` to
match (keep it ~15% larger so the wall stays visible) to get closer still.

The rig still supports the chase behaviour: with `center_bias = 0` and
`fit_ground_radius = 0` it is the original single-player camera, look-ahead and
lateral roll included, which is what `test_track.tscn` uses.

Keyboard accelerate is **Shift only**: the dash took Space, and the two cannot
share a key.

## Online multiplayer (Steam)

Press **Y / O** on the join screen to open `scenes/online_lobby.tscn`. Host
creates a friends-only Steam lobby; friends join through an overlay invite,
"Join Game" on the Steam friends list, the lobby's "Friends playing" button, or
by pasting the lobby code. The host presses **Start match**; **Backspace** (host)
takes everyone back to the lobby. Everything lives in `scripts/networking/`.

Transport is GodotSteam's built-in `SteamMultiplayerPeer`, bound to the lobby
with `host_with_lobby` / `connect_to_lobby`. Traffic rides Steam Datagram
Relay, so there is no port forwarding and no NAT setup. `no_nagle` is on so a
small packet goes out the tick it is written instead of being batched.

**Host-authoritative with client-side prediction** (`net_match_sync.gd`):

- The host simulates every car. Remote cars are driven through the ordinary
  `PlayerVehicleDriver`, fed by a `NetworkInputDevice` that holds the owner's
  newest input frame, so nothing on the vehicle side knows about the network.
- The host sends a snapshot of every car each physics tick (60 Hz, ~50 bytes
  per car, packed floats, unreliable).
- **Your own car is predicted**: it simulates locally from your input the same
  tick you press it. Each snapshot carries the input tick the host last
  consumed for you; the client compares the host's state with its own recorded
  state for that tick and eases the difference out (`correction_rate`), or
  snaps past `snap_distance`. History newer than the ack is shifted by the same
  correction, or the next snapshot would correct the same error twice.
- **Everyone else's car is a puppet**: simulation off, drawn
  `interpolation_delay_ticks` (3, ~50 ms) behind the newest snapshot, coasting
  on velocity for up to `extrapolation_limit_ticks` when packets stop.
- **Only the host scores.** `ClashArbiter.report` returns early when
  `multiplayer.is_server()` is false. Offline the default peer counts as the
  server, so the couch game and every test are unaffected. The host broadcasts
  contests (clients re-emit `contest_resolved`, so `ImpactFx` plays hit stop,
  shake and shockwave exactly as offline), impacts (the owning client replays
  knockback and stagger on its predicted car via `VehicleCombat.apply_reactions`)
  and eliminations. Health comes from the snapshots through
  `set_network_health`, which never emits `destroyed`.
- Nobody drives until every machine has loaded the arena, or 10 s pass.

Testing notes:

- App id is still **480 (Spacewar)**. Everyone needs Steam running and signed
  in, and your friends' Steam status will say "Spacewar". Lobbies are tagged
  `game=caddy_smash` so a stranger's Spacewar lobby is rejected.
- Friends need an exported build of the same commit. Two copies on one PC
  cannot test this: Steam allows one signed-in user per machine.
- Tuning presets (F2/F3) and debug-menu edits are **local only**. Change them
  on one machine and the prediction on the others drifts; keep everyone on the
  same numbers.

## Feel layer

`scripts/vehicle/vehicle_feel.gd` is the port of `UCaddyVehicleFeelComponent`.
Everything it does is applied to the `Visual` node inside `vehicle.tscn`, which
holds the meshes — the collision body and all the physics above it are never
touched. A harness check asserts exactly that.

Two continuous layers ease toward a target every frame (acceleration
squash/stretch, lateral lean, engine idle wobble). Two one-shot layers run an
eased envelope and add on top:

- **Dash** — anticipation squash that builds with charge alpha, then a stretch
  along the length axis on release, scaled by how long it was held.
- **Impact** — squash along whichever local axis took the hit, bulging across it,
  plus a position and rotation kick. The hit direction is stored in *local* space
  so the squash follows the body as it spins out.

**Nothing is linear.** `scripts/util/easing.gd` holds the curves, and the harness
verifies each one departs from the straight line between its endpoints, that the
pulse envelopes start and end at rest, and that `out_back`/`pulse_back` overshoot
— that overshoot is what gives a hit its snap. Every effect also takes an
optional `Curve` override in `FeelTuning`, mirroring how UE exposed `UCurveFloat`
with an analytic fallback.

## Momentum contest

Car-on-car impacts are decided by an explicit, visible rule rather than by tick
order. Every car sits in one of three momentum states
(`scripts/combat/vehicle_momentum.gd`); **the higher state wins the contest
outright and takes no damage at all**, and equal states are a CLASH where both
sides pay a reduced price and spin out.

Momentum = speed picks a base tier, a genuine slide raises it one, an active dash
forces the top. It uses **lateral slip, not `is_drifting`** — with grip unheld,
the default and the shipping feel, `is_drifting` is always true and says nothing
about commitment. The same flaw was quietly making the 1.1x
`drifting_impact_multiplier` a constant on every hit ever landed; that is fixed by
populating `VehicleCollisionEvent.is_drifting` from real slip.

The tier is deliberately sticky — hysteresis on the way down plus a minimum dwell
time — because a flickering state makes the outline strobe and the rule feel
arbitrary.

### Why ClashArbiter exists

Collisions used to be resolved by whichever car's `_physics_process` ran first,
which is tree order, which is spawn order, which is **player number**.
`_handle_blocking_collision` rewrites its own velocity while resolving, so the
second car swept into an opponent already slowed and turned. Measured on a
symmetric head-on: the first-moving car scored on 44.0 m/s of closing speed and
the other on 14.2 — a deterministic **3.1x advantage to P1**.

`scripts/combat/clash_arbiter.gd` (autoload) fixes it by snapshotting every car's
velocity at `process_physics_priority = -100`, before anything has moved, and
resolving each pair exactly once per frame from that snapshot. Closing speed
becomes a property of the crash rather than of the tick order. Scoring still runs
through each car's own `ImpactAdjudicator.adjudicate()` — only the closing speed
is corrected — and the per-attacker cooldown moved to a per-pair one.

`tests/head_on_probe.gd` is the standing proof: it runs the same crash in both
orders and both must report identical damage.

The arbiter re-emits `impact_dealt` once per resolution so the debug readout keeps
working, and `ImpactFx` ignores vehicle-target impacts on that signal — it drives
car effects from `contest_resolved` instead. Handling both would fire hit stop,
shake and VFX twice per crash.

### Readability

Each tier gets a signature nothing else shares, so the state is legible before
the crash rather than after it:

| | outline | trail | extras |
|---|---|---|---|
| **LOW** | none | **none, even mid-slide** | — |
| **MID** | steady, tier colour | **always, even driving straight** | — |
| **HIGH** | exaggerated (2.4x) + pulsing | always, strongest | tire sparks |

The trail is gated on **momentum, not on sliding** — it has to agree with the
outline, so a sliding LOW car lays nothing down and a straight-line MID car does.
Slip still modulates width and brightness *within* a tier.

The inverted-hull outline in `VehicleFeel` serves both jobs: an
impact flash combines by taking whichever of the two is stronger, so a hit always
reads and momentum never masks it. On resolution the shockwave takes the winner's
player colour, and a CLASH gets the heaviest freeze in the game.

## Hit emphasis

Three systems layered on top of the mesh deformation, all scaled by impact tier:

- **`scripts/fx/hit_stop.gd`** (autoload `HitStop`) — a near-freeze followed by an
  eased slow-motion tail. It must be a single owner: four cars colliding in one
  frame would each write `Engine.time_scale` and the last would win, so requests
  merge instead — strongest freeze, longest slow. It runs on real time from
  `Time.get_ticks_usec()`, because the frame delta is itself scaled by what it
  sets and would stretch the freeze indefinitely.
- **Camera shake** — trauma on `VehicleCameraRig`, squared before use so small
  knocks stay subtle and big ones spike. Driven by `FastNoiseLite`, not per-frame
  random, which strobes and reads as a broken frame rather than an impact.
- **`scripts/fx/impact_vfx.gd`** — spark burst plus a **spiky** star ring, built
  in code and self-freeing. The ring is deliberately short and front-loaded: it
  starts already at readable size, snaps outward on an exponential ease-out, then
  holds its brightness and drops out late (`EASE_IN` on alpha). A slow, evenly
  fading ring reads as a bubble rather than a hit. `spiky_ring_mesh` builds a flat
  band with alternating spike and notch radii, directly in the XZ plane so it
  needs no rotation.

**The car swells on impact, it does not shrink.** The original port squashed it,
which reads as the car *losing* rather than as it landing a hit. `impact_inflate`
grows every axis and `impact_directional_bias` keeps the hit direction legible by
growing the struck axis least. An inverted-hull outline flashes with the same
envelope — built as separate mesh copies rather than a `next_pass`, because
`MatchManager` replaces the body material to tint each player and would drop it.

**Drift trails** (`scripts/fx/drift_trail.gd`) lay glowing skid ribbons from the
rear wheels once lateral slip passes `slip_threshold`. Rebuilt each frame as an
`ImmediateMesh`, sampled per metre travelled rather than per frame, `top_level`
so the ribbon stays in world space instead of dragging behind the car. Tinted
with the player colour, so a trail identifies its owner.

**Charge anticipation** builds three things together off charge alpha, all through
an ease so they load late: the body compresses, it shudders in time with the
wiggle, and the wiggle itself accelerates from `charge_wiggle_base_hz` to
`charge_wiggle_max_hz`. The tail swing yaws the body and shoves it laterally
*against* that yaw, so the nose stays roughly planted and the back end swings.

`ImpactFx` doses these once per hit. It listens to the *scored* car-on-car hit
(`ImpactAdjudicator.impact_dealt`) for the full treatment, and separately to wall
contact for sparks and a little shake — a wall scrape must never freeze the match.

## Debug menu

`scripts/debug/debug_menu.gd`, toggled with **F1**. Unreal's
`UCaddyVehicleDebugPanelProvider` was read-only — it gathered label/value rows for
Core, Input, Tuning, Feel, Skill, Camera, Collision and DebugDraw. Same areas
here, but the tuning tabs are **editable and saveable**, which the Unreal version
could not do.

`TuningPanel` builds its rows by reflection over a Resource's
`get_property_list()`, so any new `@export` in a tuning script appears with no
extra work, `@export_group` becomes a section header, and `@export_range` supplies
the spin box bounds. Edits write to the Resource immediately, and every car shares
that instance, so a dragged value is felt at once.

- **Dirty state** — any value differing from the last saved state is bold and
  amber, shows its previous value inline, and marks its tab with `*`.
- **Save** — pops a confirm dialog listing every pending change as
  `property: old -> new`, then writes each changed Resource back to its `.tres`.
- **Revert** — restores every edited value from the baseline.

Camera settings moved out of node exports into a `CameraTuning` Resource for this
reason: node properties cannot be saved without writing the whole scene, and the
camera is exactly what needs tuning. `camera_arena.tres` is the anchored top-down
shot, `camera_chase.tres` the original single-player chase camera.

## Arena

`scripts/arena/circular_arena.gd` builds the round arena in code: a ring of flat
box segments (64 by default), pillars, and a disc floor. Godot has no inside-out
primitive and a concave trimesh is fragile against `CharacterBody3D` sweeps, so
the wall is a polygon. That also suits the arcade glide, which works off one
surface normal per contact — at 64 segments the normal turns 5.6° per joint.

## Ported so far

| Godot | Unreal |
|---|---|
| `scripts/vehicle/arcade_vehicle.gd` | `UArcadeVehicleMovementComponent` — gas, handling, drift, reverse steering, arcade wall glide |
| `scripts/vehicle/vehicle_tuning.gd` | `UCaddyVehicleTuningDataAsset` — Gas, Handling, Collision configs |
| `scripts/vehicle/brake_dash_skill.gd` | `UCaddyVehicleSkillComponent` + `UCaddyVehicleBrakeDashAbility` |
| `scripts/vehicle/skill_tuning.gd` | `FCaddyVehicleBrakeDashSkillConfig` |
| `scripts/vehicle/vehicle_collision_event.gd` | the `Attr.Collision.*` HitRegister attribute payload |
| `scripts/combat/impact_adjudicator.gd` | `UHRN_AdjudicateVehicleCollision` + `UHRN_EmitVehicleCollisionGameplayEvents` |
| `scripts/combat/impact_tuning.gd` | those two nodes' config, plus the gates from `FCaddyVehicleCollisionHitRegisterConfig` |
| `scripts/combat/vehicle_combat.gd` | `UCaddyVehicleAttributeSet`, the damageable component, `UCaddyVehicleKnockbackAbility`, `UCaddyVehicleStaggerAbility` |
| `scripts/combat/combat_tuning.gd` | attribute defaults plus both abilities' tier tables |
| `scripts/combat/impact_tier.gd` | `EHRVehicleCollisionImpactTier` |
| `scripts/vehicle/player_vehicle_driver.gd` | `ACaddyVehiclePawn` input half |
| `scripts/camera/vehicle_camera_rig.gd` | `UCaddyVehicleCameraComponent` + SpringArm rig |
| `scripts/util/ue_math.gd` | `FMath::FInterpTo` / `VInterpTo` / `FInterpConstantTo` / `InterpEaseInOut` |

## Not ported yet

- The HitRegister pipeline itself. Unreal's node graph, gameplay tags and
  attribute maps are replaced by direct calls: attacker's `ImpactAdjudicator`
  scores the hit, then calls `receive_impact` on the target's `VehicleCombat`.
  Same attacker → target flow, no tag plumbing.
- GAS. No ability system, no gameplay effects, no attribute replication.
- Feel layer (`UCaddyVehicleFeelComponent`): engine vibration, squash/stretch,
  lean, impact pulse, hit stop.
- Unreal's replication itself. The Unreal build is server-authoritative with
  client input RPCs; online play here takes the same shape over Steam (see
  Online multiplayer) but is its own implementation, not a port.

## Conversions applied

- **Units**: Unreal cm → Godot m (÷100). Interp speeds and angles are unitless
  and carry over unchanged. Every value in `vehicle_tuning.gd` notes its UE default.
- **Axes**: UE is left-handed, +X forward / +Y right / +Z up. Godot is
  right-handed, −Z forward / +X right / +Y up. `UeMath.heading_to_yaw` and
  `yaw_to_heading` are the only places that convert between a planar direction
  and a yaw — go through them.
- **Interpolation**: Godot's `lerp` is not Unreal's `FInterpTo`. Use `UeMath`,
  or the ported tuning numbers stop meaning what they meant.

## Deliberate differences from the Unreal build

- **Drift is the resting state, expressed directly.** Unreal reached this via
  `bInvertDriftInput = true` computing `Effective = 1 - Raw`, so an unheld button
  meant "drifting". That inversion is gone; the input channel is now `grip_input`
  where 0 is the car's default loose state. The button is a tuning aid for A/B-ing
  the two friction values and is earmarked for another mechanic.
- **`move_intent_dead_zone` is applied to the raw stick**, before normalising.
  In Unreal `ComputeWorldMoveIntent` normalised first, so `SetMoveIntent`'s dead
  zone test could never fire for a player and Enhanced Input's own dead zone did
  the work. Godot's InputMap has a per-action dead zone too (0.2), so the
  structure matches; the field is just no longer dead.
- **Camera yaw is world-fixed at 0**, matching the Unreal boom's
  `SetUsingAbsoluteRotation(true)`. This is load-bearing: move intent is
  camera-relative, so rotating `CameraRig` rotates the control scheme.
- **One brake-dash state machine, not two.** Unreal ran the same Ready → Braking
  → Charging → Dashing logic in both `UCaddyVehicleSkillComponent::TickComponent`
  and `UCaddyVehicleBrakeDashAbility` on a 120 Hz GAS timer, selected by
  `bUseGASAbilityStateMachine`. There is one copy here, ticked at the physics rate.
- **Skill target lock uses a `ShapeCast3D` plus a group name** in place of GAS
  target actors and `UHitRegisterTargetingProfile`. Same sweep shape and nearest-
  candidate selection; off by default, as in the Unreal config.

- **Knockback cancels an active brake-dash.** Unreal let the dash ability and the
  knockback ability both hold `SetExternalVelocityControlEnabled(true)`, so
  whichever finished first handed control back while the other was still running.
  `VehicleCombat` aborts the skill first, keeping one owner of velocity at a time.
- **Damage is a plain clamped subtraction.** Unreal routed it through an
  `IncomingDamage` meta attribute and `PostGameplayEffectExecute`; without GAS
  that indirection buys nothing.

## Implementation notes

- `_perform_movement` uses `move_and_collide` in an explicit iteration loop, not
  `move_and_slide`. `move_and_slide` runs its own slide resolution and rewrites
  velocity, which would fight the arcade glide response.
- Physics tick order is set by `process_physics_priority`: input driver `-10`,
  skill `-5`, combat `-4`, vehicle `0`. So each frame runs input → skill override
  → knockback override → movement. Reordering these desyncs effects by a frame.
- **Hand-written `.tscn` files must declare node exports in the node header.**
  An `@export var foo: SomeNode` assigned as `foo = NodePath("../Bar")` resolves
  to **null** unless the header also lists it:

  ```
  [node name="Thing" type="Node" parent="." node_paths=PackedStringArray("foo")]
  foo = NodePath("../Bar")
  ```

  The editor writes this automatically; authoring scenes by hand does not. It
  fails silently — every such export was null for a while here, and the scripts
  limped along on their `get_parent()` fallbacks in `_ready`, so nothing errored.
  Resource exports (`ExtResource`) are unaffected.
- **`_ready` is too early to touch sibling nodes.** While it runs the rest of the
  scene is still being built: `add_child` on a sibling fails with "parent node is
  busy setting up children", and node exports have not resolved. `MatchManager`
  defers its spawn with `call_deferred` for exactly this.
- **Keep shared types leaf-level.** GDScript handles cyclic `class_name`
  dependencies badly: two classes referencing each other made the resolver spin
  and eat memory rather than report an error. `ImpactTier` exists as its own
  script for exactly this reason — do not fold the enum back into
  `ImpactAdjudicator`.
