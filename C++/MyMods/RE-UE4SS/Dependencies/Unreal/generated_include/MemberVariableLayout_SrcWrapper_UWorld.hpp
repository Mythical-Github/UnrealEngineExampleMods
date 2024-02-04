std::unordered_map<File::StringType, int32_t> UWorld::MemberOffsets{};

int32& UWorld::GetActiveLevelCollectionIndex()
{
    static auto offset = MemberOffsets.find(STR("ActiveLevelCollectionIndex"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::ActiveLevelCollectionIndex' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UWorld::GetActiveLevelCollectionIndex() const
{
    static auto offset = MemberOffsets.find(STR("ActiveLevelCollectionIndex"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::ActiveLevelCollectionIndex' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

uint32& UWorld::GetAudioDeviceHandle()
{
    static auto offset = MemberOffsets.find(STR("AudioDeviceHandle"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::AudioDeviceHandle' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UWorld::GetAudioDeviceHandle() const
{
    static auto offset = MemberOffsets.find(STR("AudioDeviceHandle"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::AudioDeviceHandle' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

float& UWorld::GetAudioTimeSeconds()
{
    static auto offset = MemberOffsets.find(STR("AudioTimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::AudioTimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& UWorld::GetAudioTimeSeconds() const
{
    static auto offset = MemberOffsets.find(STR("AudioTimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::AudioTimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

int32& UWorld::GetBlockTillLevelStreamingCompletedEpoch()
{
    static auto offset = MemberOffsets.find(STR("BlockTillLevelStreamingCompletedEpoch"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::BlockTillLevelStreamingCompletedEpoch' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UWorld::GetBlockTillLevelStreamingCompletedEpoch() const
{
    static auto offset = MemberOffsets.find(STR("BlockTillLevelStreamingCompletedEpoch"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::BlockTillLevelStreamingCompletedEpoch' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

double& UWorld::GetBuildStreamingDataTimer()
{
    static auto offset = MemberOffsets.find(STR("BuildStreamingDataTimer"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::BuildStreamingDataTimer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<double*>(this, offset->second);
}
const double& UWorld::GetBuildStreamingDataTimer() const
{
    static auto offset = MemberOffsets.find(STR("BuildStreamingDataTimer"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::BuildStreamingDataTimer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const double*>(this, offset->second);
}

uint32& UWorld::GetCleanupWorldTag()
{
    static auto offset = MemberOffsets.find(STR("CleanupWorldTag"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::CleanupWorldTag' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UWorld::GetCleanupWorldTag() const
{
    static auto offset = MemberOffsets.find(STR("CleanupWorldTag"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::CleanupWorldTag' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

FName& UWorld::GetCommittedPersistentLevelName()
{
    static auto offset = MemberOffsets.find(STR("CommittedPersistentLevelName"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::CommittedPersistentLevelName' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& UWorld::GetCommittedPersistentLevelName() const
{
    static auto offset = MemberOffsets.find(STR("CommittedPersistentLevelName"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::CommittedPersistentLevelName' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

FName& UWorld::GetDebugDrawTraceTag()
{
    static auto offset = MemberOffsets.find(STR("DebugDrawTraceTag"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::DebugDrawTraceTag' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& UWorld::GetDebugDrawTraceTag() const
{
    static auto offset = MemberOffsets.find(STR("DebugDrawTraceTag"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::DebugDrawTraceTag' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

float& UWorld::GetDeltaRealTimeSeconds()
{
    static auto offset = MemberOffsets.find(STR("DeltaRealTimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::DeltaRealTimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& UWorld::GetDeltaRealTimeSeconds() const
{
    static auto offset = MemberOffsets.find(STR("DeltaRealTimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::DeltaRealTimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

float& UWorld::GetDeltaTimeSeconds()
{
    static auto offset = MemberOffsets.find(STR("DeltaTimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::DeltaTimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& UWorld::GetDeltaTimeSeconds() const
{
    static auto offset = MemberOffsets.find(STR("DeltaTimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::DeltaTimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >& UWorld::GetExtraReferencedObjects()
{
    static auto offset = MemberOffsets.find(STR("ExtraReferencedObjects"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::ExtraReferencedObjects' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >& UWorld::GetExtraReferencedObjects() const
{
    static auto offset = MemberOffsets.find(STR("ExtraReferencedObjects"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::ExtraReferencedObjects' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

bool& UWorld::GetFullPurgeTriggered()
{
    static auto offset = MemberOffsets.find(STR("FullPurgeTriggered"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::FullPurgeTriggered' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UWorld::GetFullPurgeTriggered() const
{
    static auto offset = MemberOffsets.find(STR("FullPurgeTriggered"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::FullPurgeTriggered' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

uint32& UWorld::GetIsInBlockTillLevelStreamingCompleted()
{
    static auto offset = MemberOffsets.find(STR("IsInBlockTillLevelStreamingCompleted"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::IsInBlockTillLevelStreamingCompleted' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UWorld::GetIsInBlockTillLevelStreamingCompleted() const
{
    static auto offset = MemberOffsets.find(STR("IsInBlockTillLevelStreamingCompleted"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::IsInBlockTillLevelStreamingCompleted' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint32& UWorld::GetLWILastAssignedUID()
{
    static auto offset = MemberOffsets.find(STR("LWILastAssignedUID"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::LWILastAssignedUID' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UWorld::GetLWILastAssignedUID() const
{
    static auto offset = MemberOffsets.find(STR("LWILastAssignedUID"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::LWILastAssignedUID' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

double& UWorld::GetLastTimeUnbuiltLightingWasEncountered()
{
    static auto offset = MemberOffsets.find(STR("LastTimeUnbuiltLightingWasEncountered"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::LastTimeUnbuiltLightingWasEncountered' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<double*>(this, offset->second);
}
const double& UWorld::GetLastTimeUnbuiltLightingWasEncountered() const
{
    static auto offset = MemberOffsets.find(STR("LastTimeUnbuiltLightingWasEncountered"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::LastTimeUnbuiltLightingWasEncountered' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const double*>(this, offset->second);
}

TArray<AActor *,TSizedDefaultAllocator<32> >& UWorld::GetLevelSequenceActors()
{
    static auto offset = MemberOffsets.find(STR("LevelSequenceActors"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::LevelSequenceActors' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<AActor *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<AActor *,TSizedDefaultAllocator<32> >& UWorld::GetLevelSequenceActors() const
{
    static auto offset = MemberOffsets.find(STR("LevelSequenceActors"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::LevelSequenceActors' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<AActor *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

float& UWorld::GetNextSwitchCountdown()
{
    static auto offset = MemberOffsets.find(STR("NextSwitchCountdown"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NextSwitchCountdown' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& UWorld::GetNextSwitchCountdown() const
{
    static auto offset = MemberOffsets.find(STR("NextSwitchCountdown"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NextSwitchCountdown' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

FString& UWorld::GetNextURL()
{
    static auto offset = MemberOffsets.find(STR("NextURL"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NextURL' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FString*>(this, offset->second);
}
const FString& UWorld::GetNextURL() const
{
    static auto offset = MemberOffsets.find(STR("NextURL"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NextURL' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FString*>(this, offset->second);
}

uint32& UWorld::GetNumInvalidReflectionCaptureComponents()
{
    static auto offset = MemberOffsets.find(STR("NumInvalidReflectionCaptureComponents"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumInvalidReflectionCaptureComponents' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UWorld::GetNumInvalidReflectionCaptureComponents() const
{
    static auto offset = MemberOffsets.find(STR("NumInvalidReflectionCaptureComponents"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumInvalidReflectionCaptureComponents' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint32& UWorld::GetNumLightingUnbuiltObjects()
{
    static auto offset = MemberOffsets.find(STR("NumLightingUnbuiltObjects"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumLightingUnbuiltObjects' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UWorld::GetNumLightingUnbuiltObjects() const
{
    static auto offset = MemberOffsets.find(STR("NumLightingUnbuiltObjects"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumLightingUnbuiltObjects' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint16& UWorld::GetNumStreamingLevelsBeingLoaded()
{
    static auto offset = MemberOffsets.find(STR("NumStreamingLevelsBeingLoaded"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumStreamingLevelsBeingLoaded' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint16*>(this, offset->second);
}
const uint16& UWorld::GetNumStreamingLevelsBeingLoaded() const
{
    static auto offset = MemberOffsets.find(STR("NumStreamingLevelsBeingLoaded"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumStreamingLevelsBeingLoaded' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint16*>(this, offset->second);
}

int32& UWorld::GetNumTextureStreamingDirtyResources()
{
    static auto offset = MemberOffsets.find(STR("NumTextureStreamingDirtyResources"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumTextureStreamingDirtyResources' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UWorld::GetNumTextureStreamingDirtyResources() const
{
    static auto offset = MemberOffsets.find(STR("NumTextureStreamingDirtyResources"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumTextureStreamingDirtyResources' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

int32& UWorld::GetNumTextureStreamingUnbuiltComponents()
{
    static auto offset = MemberOffsets.find(STR("NumTextureStreamingUnbuiltComponents"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumTextureStreamingUnbuiltComponents' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UWorld::GetNumTextureStreamingUnbuiltComponents() const
{
    static auto offset = MemberOffsets.find(STR("NumTextureStreamingUnbuiltComponents"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumTextureStreamingUnbuiltComponents' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

uint32& UWorld::GetNumUnbuiltReflectionCaptures()
{
    static auto offset = MemberOffsets.find(STR("NumUnbuiltReflectionCaptures"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumUnbuiltReflectionCaptures' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UWorld::GetNumUnbuiltReflectionCaptures() const
{
    static auto offset = MemberOffsets.find(STR("NumUnbuiltReflectionCaptures"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::NumUnbuiltReflectionCaptures' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

FVector& UWorld::GetOriginOffsetThisFrame()
{
    static auto offset = MemberOffsets.find(STR("OriginOffsetThisFrame"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::OriginOffsetThisFrame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FVector*>(this, offset->second);
}
const FVector& UWorld::GetOriginOffsetThisFrame() const
{
    static auto offset = MemberOffsets.find(STR("OriginOffsetThisFrame"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::OriginOffsetThisFrame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FVector*>(this, offset->second);
}

float& UWorld::GetPauseDelay()
{
    static auto offset = MemberOffsets.find(STR("PauseDelay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::PauseDelay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& UWorld::GetPauseDelay() const
{
    static auto offset = MemberOffsets.find(STR("PauseDelay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::PauseDelay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >& UWorld::GetPerModuleDataObjects()
{
    static auto offset = MemberOffsets.find(STR("PerModuleDataObjects"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::PerModuleDataObjects' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >& UWorld::GetPerModuleDataObjects() const
{
    static auto offset = MemberOffsets.find(STR("PerModuleDataObjects"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::PerModuleDataObjects' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

int32& UWorld::GetPlayerNum()
{
    static auto offset = MemberOffsets.find(STR("PlayerNum"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::PlayerNum' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UWorld::GetPlayerNum() const
{
    static auto offset = MemberOffsets.find(STR("PlayerNum"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::PlayerNum' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

TArray<FName,TSizedDefaultAllocator<32> >& UWorld::GetPreparingLevelNames()
{
    static auto offset = MemberOffsets.find(STR("PreparingLevelNames"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::PreparingLevelNames' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FName,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FName,TSizedDefaultAllocator<32> >& UWorld::GetPreparingLevelNames() const
{
    static auto offset = MemberOffsets.find(STR("PreparingLevelNames"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::PreparingLevelNames' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FName,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

float& UWorld::GetRealTimeSeconds()
{
    static auto offset = MemberOffsets.find(STR("RealTimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::RealTimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& UWorld::GetRealTimeSeconds() const
{
    static auto offset = MemberOffsets.find(STR("RealTimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::RealTimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

FString& UWorld::GetStreamingLevelsPrefix()
{
    static auto offset = MemberOffsets.find(STR("StreamingLevelsPrefix"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::StreamingLevelsPrefix' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FString*>(this, offset->second);
}
const FString& UWorld::GetStreamingLevelsPrefix() const
{
    static auto offset = MemberOffsets.find(STR("StreamingLevelsPrefix"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::StreamingLevelsPrefix' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FString*>(this, offset->second);
}

int32& UWorld::GetStreamingVolumeUpdateDelay()
{
    static auto offset = MemberOffsets.find(STR("StreamingVolumeUpdateDelay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::StreamingVolumeUpdateDelay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UWorld::GetStreamingVolumeUpdateDelay() const
{
    static auto offset = MemberOffsets.find(STR("StreamingVolumeUpdateDelay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::StreamingVolumeUpdateDelay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

float& UWorld::GetTimeSeconds()
{
    static auto offset = MemberOffsets.find(STR("TimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::TimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& UWorld::GetTimeSeconds() const
{
    static auto offset = MemberOffsets.find(STR("TimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::TimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

float& UWorld::GetTimeSinceLastPendingKillPurge()
{
    static auto offset = MemberOffsets.find(STR("TimeSinceLastPendingKillPurge"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::TimeSinceLastPendingKillPurge' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& UWorld::GetTimeSinceLastPendingKillPurge() const
{
    static auto offset = MemberOffsets.find(STR("TimeSinceLastPendingKillPurge"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::TimeSinceLastPendingKillPurge' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

float& UWorld::GetUnpausedTimeSeconds()
{
    static auto offset = MemberOffsets.find(STR("UnpausedTimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::UnpausedTimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& UWorld::GetUnpausedTimeSeconds() const
{
    static auto offset = MemberOffsets.find(STR("UnpausedTimeSeconds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::UnpausedTimeSeconds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

TArray<FVector,TSizedDefaultAllocator<32> >& UWorld::GetViewLocationsRenderedLastFrame()
{
    static auto offset = MemberOffsets.find(STR("ViewLocationsRenderedLastFrame"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::ViewLocationsRenderedLastFrame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FVector,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FVector,TSizedDefaultAllocator<32> >& UWorld::GetViewLocationsRenderedLastFrame() const
{
    static auto offset = MemberOffsets.find(STR("ViewLocationsRenderedLastFrame"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::ViewLocationsRenderedLastFrame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FVector,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

uint8& UWorld::GetbActorsInitialized()
{
    static auto offset = MemberOffsets.find(STR("bActorsInitialized"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bActorsInitialized' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbActorsInitialized() const
{
    static auto offset = MemberOffsets.find(STR("bActorsInitialized"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bActorsInitialized' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbAggressiveLOD()
{
    static auto offset = MemberOffsets.find(STR("bAggressiveLOD"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bAggressiveLOD' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbAggressiveLOD() const
{
    static auto offset = MemberOffsets.find(STR("bAggressiveLOD"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bAggressiveLOD' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbAllowAudioPlayback()
{
    static auto offset = MemberOffsets.find(STR("bAllowAudioPlayback"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bAllowAudioPlayback' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbAllowAudioPlayback() const
{
    static auto offset = MemberOffsets.find(STR("bAllowAudioPlayback"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bAllowAudioPlayback' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

bool& UWorld::GetbAllowDeferredPhysicsStateCreation()
{
    static auto offset = MemberOffsets.find(STR("bAllowDeferredPhysicsStateCreation"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bAllowDeferredPhysicsStateCreation' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UWorld::GetbAllowDeferredPhysicsStateCreation() const
{
    static auto offset = MemberOffsets.find(STR("bAllowDeferredPhysicsStateCreation"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bAllowDeferredPhysicsStateCreation' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

uint8& UWorld::GetbAreConstraintsDirty()
{
    static auto offset = MemberOffsets.find(STR("bAreConstraintsDirty"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bAreConstraintsDirty' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbAreConstraintsDirty() const
{
    static auto offset = MemberOffsets.find(STR("bAreConstraintsDirty"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bAreConstraintsDirty' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbBegunPlay()
{
    static auto offset = MemberOffsets.find(STR("bBegunPlay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bBegunPlay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbBegunPlay() const
{
    static auto offset = MemberOffsets.find(STR("bBegunPlay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bBegunPlay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint32& UWorld::GetbCleanedUpWorld()
{
    static auto offset = MemberOffsets.find(STR("bCleanedUpWorld"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bCleanedUpWorld' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UWorld::GetbCleanedUpWorld() const
{
    static auto offset = MemberOffsets.find(STR("bCleanedUpWorld"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bCleanedUpWorld' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

bool& UWorld::GetbCreateRenderStateForHiddenComponents()
{
    static auto offset = MemberOffsets.find(STR("bCreateRenderStateForHiddenComponents"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bCreateRenderStateForHiddenComponents' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UWorld::GetbCreateRenderStateForHiddenComponents() const
{
    static auto offset = MemberOffsets.find(STR("bCreateRenderStateForHiddenComponents"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bCreateRenderStateForHiddenComponents' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

bool& UWorld::GetbDebugDrawAllTraceTags()
{
    static auto offset = MemberOffsets.find(STR("bDebugDrawAllTraceTags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bDebugDrawAllTraceTags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UWorld::GetbDebugDrawAllTraceTags() const
{
    static auto offset = MemberOffsets.find(STR("bDebugDrawAllTraceTags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bDebugDrawAllTraceTags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

uint32& UWorld::GetbDebugFrameStepExecution()
{
    static auto offset = MemberOffsets.find(STR("bDebugFrameStepExecution"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bDebugFrameStepExecution' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UWorld::GetbDebugFrameStepExecution() const
{
    static auto offset = MemberOffsets.find(STR("bDebugFrameStepExecution"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bDebugFrameStepExecution' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint8& UWorld::GetbDebugPauseExecution()
{
    static auto offset = MemberOffsets.find(STR("bDebugPauseExecution"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bDebugPauseExecution' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbDebugPauseExecution() const
{
    static auto offset = MemberOffsets.find(STR("bDebugPauseExecution"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bDebugPauseExecution' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbDoDelayedUpdateCullDistanceVolumes()
{
    static auto offset = MemberOffsets.find(STR("bDoDelayedUpdateCullDistanceVolumes"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bDoDelayedUpdateCullDistanceVolumes' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbDoDelayedUpdateCullDistanceVolumes() const
{
    static auto offset = MemberOffsets.find(STR("bDoDelayedUpdateCullDistanceVolumes"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bDoDelayedUpdateCullDistanceVolumes' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbDropDetail()
{
    static auto offset = MemberOffsets.find(STR("bDropDetail"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bDropDetail' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbDropDetail() const
{
    static auto offset = MemberOffsets.find(STR("bDropDetail"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bDropDetail' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

bool& UWorld::GetbHack_Force_UsesGameHiddenFlags_True()
{
    static auto offset = MemberOffsets.find(STR("bHack_Force_UsesGameHiddenFlags_True"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bHack_Force_UsesGameHiddenFlags_True' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UWorld::GetbHack_Force_UsesGameHiddenFlags_True() const
{
    static auto offset = MemberOffsets.find(STR("bHack_Force_UsesGameHiddenFlags_True"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bHack_Force_UsesGameHiddenFlags_True' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

uint8& UWorld::GetbInTick()
{
    static auto offset = MemberOffsets.find(STR("bInTick"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bInTick' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbInTick() const
{
    static auto offset = MemberOffsets.find(STR("bInTick"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bInTick' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbInitializedAndNeedsCleanup()
{
    static auto offset = MemberOffsets.find(STR("bInitializedAndNeedsCleanup"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bInitializedAndNeedsCleanup' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbInitializedAndNeedsCleanup() const
{
    static auto offset = MemberOffsets.find(STR("bInitializedAndNeedsCleanup"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bInitializedAndNeedsCleanup' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbIsBuilt()
{
    static auto offset = MemberOffsets.find(STR("bIsBuilt"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsBuilt' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbIsBuilt() const
{
    static auto offset = MemberOffsets.find(STR("bIsBuilt"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsBuilt' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbIsCameraMoveableWhenPaused()
{
    static auto offset = MemberOffsets.find(STR("bIsCameraMoveableWhenPaused"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsCameraMoveableWhenPaused' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbIsCameraMoveableWhenPaused() const
{
    static auto offset = MemberOffsets.find(STR("bIsCameraMoveableWhenPaused"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsCameraMoveableWhenPaused' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbIsDefaultLevel()
{
    static auto offset = MemberOffsets.find(STR("bIsDefaultLevel"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsDefaultLevel' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbIsDefaultLevel() const
{
    static auto offset = MemberOffsets.find(STR("bIsDefaultLevel"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsDefaultLevel' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbIsLevelStreamingFrozen()
{
    static auto offset = MemberOffsets.find(STR("bIsLevelStreamingFrozen"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsLevelStreamingFrozen' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbIsLevelStreamingFrozen() const
{
    static auto offset = MemberOffsets.find(STR("bIsLevelStreamingFrozen"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsLevelStreamingFrozen' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbIsRunningConstructionScript()
{
    static auto offset = MemberOffsets.find(STR("bIsRunningConstructionScript"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsRunningConstructionScript' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbIsRunningConstructionScript() const
{
    static auto offset = MemberOffsets.find(STR("bIsRunningConstructionScript"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsRunningConstructionScript' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbIsTearingDown()
{
    static auto offset = MemberOffsets.find(STR("bIsTearingDown"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsTearingDown' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbIsTearingDown() const
{
    static auto offset = MemberOffsets.find(STR("bIsTearingDown"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsTearingDown' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbIsWorldInitialized()
{
    static auto offset = MemberOffsets.find(STR("bIsWorldInitialized"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsWorldInitialized' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbIsWorldInitialized() const
{
    static auto offset = MemberOffsets.find(STR("bIsWorldInitialized"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bIsWorldInitialized' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbKismetScriptError()
{
    static auto offset = MemberOffsets.find(STR("bKismetScriptError"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bKismetScriptError' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbKismetScriptError() const
{
    static auto offset = MemberOffsets.find(STR("bKismetScriptError"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bKismetScriptError' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint32& UWorld::GetbMarkedObjectsPendingKill()
{
    static auto offset = MemberOffsets.find(STR("bMarkedObjectsPendingKill"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bMarkedObjectsPendingKill' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UWorld::GetbMarkedObjectsPendingKill() const
{
    static auto offset = MemberOffsets.find(STR("bMarkedObjectsPendingKill"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bMarkedObjectsPendingKill' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint8& UWorld::GetbMatchStarted()
{
    static auto offset = MemberOffsets.find(STR("bMatchStarted"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bMatchStarted' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbMatchStarted() const
{
    static auto offset = MemberOffsets.find(STR("bMatchStarted"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bMatchStarted' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbMaterialParameterCollectionInstanceNeedsDeferredUpdate()
{
    static auto offset = MemberOffsets.find(STR("bMaterialParameterCollectionInstanceNeedsDeferredUpdate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bMaterialParameterCollectionInstanceNeedsDeferredUpdate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbMaterialParameterCollectionInstanceNeedsDeferredUpdate() const
{
    static auto offset = MemberOffsets.find(STR("bMaterialParameterCollectionInstanceNeedsDeferredUpdate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bMaterialParameterCollectionInstanceNeedsDeferredUpdate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

bool& UWorld::GetbOriginOffsetThisFrame()
{
    static auto offset = MemberOffsets.find(STR("bOriginOffsetThisFrame"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bOriginOffsetThisFrame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UWorld::GetbOriginOffsetThisFrame() const
{
    static auto offset = MemberOffsets.find(STR("bOriginOffsetThisFrame"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bOriginOffsetThisFrame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

uint8& UWorld::GetbPlayersOnly()
{
    static auto offset = MemberOffsets.find(STR("bPlayersOnly"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bPlayersOnly' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbPlayersOnly() const
{
    static auto offset = MemberOffsets.find(STR("bPlayersOnly"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bPlayersOnly' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbPlayersOnlyPending()
{
    static auto offset = MemberOffsets.find(STR("bPlayersOnlyPending"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bPlayersOnlyPending' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbPlayersOnlyPending() const
{
    static auto offset = MemberOffsets.find(STR("bPlayersOnlyPending"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bPlayersOnlyPending' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbPostTickComponentUpdate()
{
    static auto offset = MemberOffsets.find(STR("bPostTickComponentUpdate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bPostTickComponentUpdate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbPostTickComponentUpdate() const
{
    static auto offset = MemberOffsets.find(STR("bPostTickComponentUpdate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bPostTickComponentUpdate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbRequestedBlockOnAsyncLoading()
{
    static auto offset = MemberOffsets.find(STR("bRequestedBlockOnAsyncLoading"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bRequestedBlockOnAsyncLoading' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbRequestedBlockOnAsyncLoading() const
{
    static auto offset = MemberOffsets.find(STR("bRequestedBlockOnAsyncLoading"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bRequestedBlockOnAsyncLoading' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbRequiresHitProxies()
{
    static auto offset = MemberOffsets.find(STR("bRequiresHitProxies"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bRequiresHitProxies' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbRequiresHitProxies() const
{
    static auto offset = MemberOffsets.find(STR("bRequiresHitProxies"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bRequiresHitProxies' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

bool& UWorld::GetbShouldDelayGarbageCollect()
{
    static auto offset = MemberOffsets.find(STR("bShouldDelayGarbageCollect"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bShouldDelayGarbageCollect' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UWorld::GetbShouldDelayGarbageCollect() const
{
    static auto offset = MemberOffsets.find(STR("bShouldDelayGarbageCollect"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bShouldDelayGarbageCollect' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

uint8& UWorld::GetbShouldForceUnloadStreamingLevels()
{
    static auto offset = MemberOffsets.find(STR("bShouldForceUnloadStreamingLevels"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bShouldForceUnloadStreamingLevels' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbShouldForceUnloadStreamingLevels() const
{
    static auto offset = MemberOffsets.find(STR("bShouldForceUnloadStreamingLevels"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bShouldForceUnloadStreamingLevels' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbShouldForceVisibleStreamingLevels()
{
    static auto offset = MemberOffsets.find(STR("bShouldForceVisibleStreamingLevels"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bShouldForceVisibleStreamingLevels' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbShouldForceVisibleStreamingLevels() const
{
    static auto offset = MemberOffsets.find(STR("bShouldForceVisibleStreamingLevels"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bShouldForceVisibleStreamingLevels' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbShouldSimulatePhysics()
{
    static auto offset = MemberOffsets.find(STR("bShouldSimulatePhysics"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bShouldSimulatePhysics' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbShouldSimulatePhysics() const
{
    static auto offset = MemberOffsets.find(STR("bShouldSimulatePhysics"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bShouldSimulatePhysics' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbShouldTick()
{
    static auto offset = MemberOffsets.find(STR("bShouldTick"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bShouldTick' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbShouldTick() const
{
    static auto offset = MemberOffsets.find(STR("bShouldTick"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bShouldTick' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbStartup()
{
    static auto offset = MemberOffsets.find(STR("bStartup"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bStartup' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbStartup() const
{
    static auto offset = MemberOffsets.find(STR("bStartup"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bStartup' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbStreamingDataDirty()
{
    static auto offset = MemberOffsets.find(STR("bStreamingDataDirty"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bStreamingDataDirty' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbStreamingDataDirty() const
{
    static auto offset = MemberOffsets.find(STR("bStreamingDataDirty"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bStreamingDataDirty' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbTickNewlySpawned()
{
    static auto offset = MemberOffsets.find(STR("bTickNewlySpawned"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bTickNewlySpawned' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbTickNewlySpawned() const
{
    static auto offset = MemberOffsets.find(STR("bTickNewlySpawned"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bTickNewlySpawned' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbTriggerPostLoadMap()
{
    static auto offset = MemberOffsets.find(STR("bTriggerPostLoadMap"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bTriggerPostLoadMap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbTriggerPostLoadMap() const
{
    static auto offset = MemberOffsets.find(STR("bTriggerPostLoadMap"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bTriggerPostLoadMap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& UWorld::GetbWorldWasLoadedThisTick()
{
    static auto offset = MemberOffsets.find(STR("bWorldWasLoadedThisTick"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bWorldWasLoadedThisTick' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UWorld::GetbWorldWasLoadedThisTick() const
{
    static auto offset = MemberOffsets.find(STR("bWorldWasLoadedThisTick"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UWorld::bWorldWasLoadedThisTick' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

