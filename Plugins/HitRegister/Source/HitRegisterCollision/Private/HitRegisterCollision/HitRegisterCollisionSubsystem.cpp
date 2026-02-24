#include "HitRegisterCollision/HitRegisterCollisionSubsystem.h"

#include "HitRegisterCollision/HitRegisterCollisionLog.h"
#include "HitRegisterCollision/HitRegisterCollisionSettings.h"
#include "HitRegisterCollision/HitRegisterHurtBoxComponent.h"
#include "HitRegisterCollision/HitRegisterRelationResolver.h"
#include "HitRegisterCollision/HitRegisterTargetingProfile.h"
#include "HitRegisterTeamUtils.h"
#include "HitRegister/HitRegisterSubsystem.h"
#include "HitRegister/HitRegisterPipeline.h"

namespace
{
    static EHitRegisterRelation ResolveRelation(AActor* Source, AActor* Target, const UObject* ResolverObj)
    {
        if (ResolverObj && ResolverObj->GetClass()->ImplementsInterface(UHitRegisterRelationResolver::StaticClass()))
        {
            return IHitRegisterRelationResolver::Execute_GetRelation(ResolverObj, Source, Target);
        }

        int32 TeamA = INDEX_NONE;
        int32 TeamB = INDEX_NONE;
        const bool bHasA = HitRegisterTeamUtils::TryGetTeamId(Source, TeamA);
        const bool bHasB = HitRegisterTeamUtils::TryGetTeamId(Target, TeamB);
        if (!bHasA || !bHasB)
        {
            return EHitRegisterRelation::Unknown;
        }

        return (TeamA == TeamB) ? EHitRegisterRelation::Ally : EHitRegisterRelation::Enemy;
    }

    static bool PassesTargeting(const FAttackRequest& Attack, const FHitCandidate& Candidate, const UHitRegisterTargetingProfile* Profile, const UObject* ResolverObj)
    {
        if (!Profile)
        {
            return true;
        }

        AActor* Source = Attack.Instigator.Get();
        AActor* Target = Candidate.TargetActor.Get();
        if (!Target)
        {
            return false;
        }

        switch (Profile->Mode)
        {
        case EHitTargetMode::All:
            return true;
        case EHitTargetMode::SelfOnly:
            return Source && Target == Source;
        case EHitTargetMode::AllExceptSelf:
            return !Source || Target != Source;
        case EHitTargetMode::AlliesExceptSelf:
        case EHitTargetMode::AlliesOnly:
        case EHitTargetMode::EnemiesOnly:
        {
            const EHitRegisterRelation Rel = ResolveRelation(Source, Target, ResolverObj);
            if (Rel == EHitRegisterRelation::Unknown)
            {
                return Profile->UnknownTeamPolicy == EHitTargetUnknownPolicy::Allow;
            }

            if (Profile->Mode == EHitTargetMode::AlliesOnly)
            {
                return Rel == EHitRegisterRelation::Ally;
            }
            if (Profile->Mode == EHitTargetMode::EnemiesOnly)
            {
                return Rel == EHitRegisterRelation::Enemy;
            }
            if (Profile->Mode == EHitTargetMode::AlliesExceptSelf)
            {
                return Rel == EHitRegisterRelation::Ally && Target != Source;
            }
            return true;
        }
        default:
            return true;
        }
    }
}

void UHitRegisterCollisionSubsystem::FilterCandidates(const FAttackRequest& Attack, const FHitCandidateBatch& InBatch, const UHitRegisterTargetingProfile* TargetingProfile, const FHitRegisterDedupeSettings& Settings, FHitCandidateBatch& OutBatch)
{
    OutBatch = FHitCandidateBatch{};
    if (InBatch.Candidates.Num() == 0)
    {
        return;
    }

    UObject* ResolverObj = nullptr;
    if (const UHitRegisterCollisionSettings* SettingsObj = UHitRegisterCollisionSettings::Get())
    {
        FString ValidationError;
        if (!SettingsObj->ValidateSettings(&ValidationError))
        {
            UE_LOG(LogHitRegisterCollision, Error, TEXT("%s"), *ValidationError);
        }
        else if (!SettingsObj->RelationResolver.IsNull())
        {
            ResolverObj = SettingsObj->RelationResolver.LoadSynchronous();
        }
    }

    UWorld* World = GetWorld();
    const float Now = World ? World->GetTimeSeconds() : 0.f;

    for (const FHitCandidate& Candidate : InBatch.Candidates)
    {
        if (!PassesTargeting(Attack, Candidate, TargetingProfile, ResolverObj))
        {
            OutBatch.Rejected.Add(Candidate);
            continue;
        }

        if (Settings.Policy == EHitRegisterDedupePolicy::None)
        {
            OutBatch.Candidates.Add(Candidate);
            continue;
        }

        FHitDedupeKey Key;
        Key.AttackId = Candidate.AttackId;
        Key.Instigator = Attack.Instigator;
        Key.TargetActor = Candidate.TargetActor;
        if (Settings.Policy == EHitRegisterDedupePolicy::CooldownPerHurtBox)
        {
            if (Candidate.HurtBox)
            {
                Key.HurtComponent = Candidate.HurtBox.Get();
            }
            else
            {
                Key.HurtComponent = Candidate.TargetComponent.Get();
            }
        }

        bool bAccept = true;

        if (Settings.Policy == EHitRegisterDedupePolicy::OncePerAttack)
        {
            if (LastHitTimeByKey.Contains(Key))
            {
                bAccept = false;
            }
        }
        else
        {
            const float* LastTime = LastHitTimeByKey.Find(Key);
            if (LastTime && Settings.CooldownSeconds > 0.f)
            {
                if ((Now - *LastTime) < Settings.CooldownSeconds)
                {
                    bAccept = false;
                }
            }
        }

        if (bAccept)
        {
            OutBatch.Candidates.Add(Candidate);
            LastHitTimeByKey.Add(Key, Now);
        }
        else
        {
            OutBatch.Rejected.Add(Candidate);
        }
    }
}

void UHitRegisterCollisionSubsystem::FilterCandidatesSimple(const FHitCandidateBatch& InBatch, const FHitRegisterDedupeSettings& Settings, FHitCandidateBatch& OutBatch)
{
    FAttackRequest DummyAttack;
    FilterCandidates(DummyAttack, InBatch, nullptr, Settings, OutBatch);
}

void UHitRegisterCollisionSubsystem::ExecuteForCandidates(const FAttackRequest& Attack, UHitRegisterPipeline* Pipeline, const FHitCandidateBatch& Batch, TArray<FHitRegisterContext>& OutContexts)
{
    OutContexts.Reset();
    OutContexts.Reserve(Batch.Candidates.Num());

    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    UHitRegisterSubsystem* CoreSubsystem = World->GetSubsystem<UHitRegisterSubsystem>();
    if (!CoreSubsystem)
    {
        return;
    }

    for (const FHitCandidate& Candidate : Batch.Candidates)
    {
        FHitRegisterContext Context;
        CoreSubsystem->ExecuteHitRegister(Attack, Candidate.Hit, Pipeline, Context);
        OutContexts.Add(MoveTemp(Context));
    }
}

void UHitRegisterCollisionSubsystem::FilterAndExecuteCandidates(const FAttackRequest& Attack, const FHitCandidateBatch& InBatch, const UHitRegisterTargetingProfile* TargetingProfile, const FHitRegisterDedupeSettings& Settings, UHitRegisterPipeline* Pipeline, TArray<FHitRegisterContext>& OutContexts)
{
    FHitCandidateBatch Filtered;
    FilterCandidates(Attack, InBatch, TargetingProfile, Settings, Filtered);
    ExecuteForCandidates(Attack, Pipeline, Filtered, OutContexts);
}

void UHitRegisterCollisionSubsystem::ClearDedupeForAttack(int32 AttackId, AActor* Instigator)
{
    if (LastHitTimeByKey.Num() == 0)
    {
        return;
    }

    for (auto It = LastHitTimeByKey.CreateIterator(); It; ++It)
    {
        const FHitDedupeKey& Key = It.Key();
        if (Key.AttackId != AttackId)
        {
            continue;
        }
        if (Instigator && Key.Instigator.Get() != Instigator)
        {
            continue;
        }
        It.RemoveCurrent();
    }
}

void UHitRegisterCollisionSubsystem::ClearAllDedupe()
{
    LastHitTimeByKey.Reset();
}
