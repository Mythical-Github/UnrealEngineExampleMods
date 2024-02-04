static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    int32& GetActiveLevelCollectionIndex();
    const int32& GetActiveLevelCollectionIndex() const;

public:
    uint32& GetAudioDeviceHandle();
    const uint32& GetAudioDeviceHandle() const;

public:
    float& GetAudioTimeSeconds();
    const float& GetAudioTimeSeconds() const;

public:
    int32& GetBlockTillLevelStreamingCompletedEpoch();
    const int32& GetBlockTillLevelStreamingCompletedEpoch() const;

public:
    double& GetBuildStreamingDataTimer();
    const double& GetBuildStreamingDataTimer() const;

public:
    uint32& GetCleanupWorldTag();
    const uint32& GetCleanupWorldTag() const;

public:
    FName& GetCommittedPersistentLevelName();
    const FName& GetCommittedPersistentLevelName() const;

public:
    FName& GetDebugDrawTraceTag();
    const FName& GetDebugDrawTraceTag() const;

public:
    float& GetDeltaRealTimeSeconds();
    const float& GetDeltaRealTimeSeconds() const;

public:
    float& GetDeltaTimeSeconds();
    const float& GetDeltaTimeSeconds() const;

public:
    TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >& GetExtraReferencedObjects();
    const TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >& GetExtraReferencedObjects() const;

public:
    bool& GetFullPurgeTriggered();
    const bool& GetFullPurgeTriggered() const;

public:
    uint32& GetIsInBlockTillLevelStreamingCompleted();
    const uint32& GetIsInBlockTillLevelStreamingCompleted() const;

public:
    uint32& GetLWILastAssignedUID();
    const uint32& GetLWILastAssignedUID() const;

public:
    double& GetLastTimeUnbuiltLightingWasEncountered();
    const double& GetLastTimeUnbuiltLightingWasEncountered() const;

public:
    TArray<AActor *,TSizedDefaultAllocator<32> >& GetLevelSequenceActors();
    const TArray<AActor *,TSizedDefaultAllocator<32> >& GetLevelSequenceActors() const;

public:
    float& GetNextSwitchCountdown();
    const float& GetNextSwitchCountdown() const;

public:
    FString& GetNextURL();
    const FString& GetNextURL() const;

public:
    uint32& GetNumInvalidReflectionCaptureComponents();
    const uint32& GetNumInvalidReflectionCaptureComponents() const;

public:
    uint32& GetNumLightingUnbuiltObjects();
    const uint32& GetNumLightingUnbuiltObjects() const;

public:
    uint16& GetNumStreamingLevelsBeingLoaded();
    const uint16& GetNumStreamingLevelsBeingLoaded() const;

public:
    int32& GetNumTextureStreamingDirtyResources();
    const int32& GetNumTextureStreamingDirtyResources() const;

public:
    int32& GetNumTextureStreamingUnbuiltComponents();
    const int32& GetNumTextureStreamingUnbuiltComponents() const;

public:
    uint32& GetNumUnbuiltReflectionCaptures();
    const uint32& GetNumUnbuiltReflectionCaptures() const;

public:
    FVector& GetOriginOffsetThisFrame();
    const FVector& GetOriginOffsetThisFrame() const;

public:
    float& GetPauseDelay();
    const float& GetPauseDelay() const;

public:
    TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >& GetPerModuleDataObjects();
    const TArray<TObjectPtr<UObject>,TSizedDefaultAllocator<32> >& GetPerModuleDataObjects() const;

public:
    int32& GetPlayerNum();
    const int32& GetPlayerNum() const;

public:
    TArray<FName,TSizedDefaultAllocator<32> >& GetPreparingLevelNames();
    const TArray<FName,TSizedDefaultAllocator<32> >& GetPreparingLevelNames() const;

public:
    float& GetRealTimeSeconds();
    const float& GetRealTimeSeconds() const;

public:
    FString& GetStreamingLevelsPrefix();
    const FString& GetStreamingLevelsPrefix() const;

public:
    int32& GetStreamingVolumeUpdateDelay();
    const int32& GetStreamingVolumeUpdateDelay() const;

public:
    float& GetTimeSeconds();
    const float& GetTimeSeconds() const;

public:
    float& GetTimeSinceLastPendingKillPurge();
    const float& GetTimeSinceLastPendingKillPurge() const;

public:
    float& GetUnpausedTimeSeconds();
    const float& GetUnpausedTimeSeconds() const;

public:
    TArray<FVector,TSizedDefaultAllocator<32> >& GetViewLocationsRenderedLastFrame();
    const TArray<FVector,TSizedDefaultAllocator<32> >& GetViewLocationsRenderedLastFrame() const;

public:
    uint8& GetbActorsInitialized();
    const uint8& GetbActorsInitialized() const;

public:
    uint8& GetbAggressiveLOD();
    const uint8& GetbAggressiveLOD() const;

public:
    uint8& GetbAllowAudioPlayback();
    const uint8& GetbAllowAudioPlayback() const;

public:
    bool& GetbAllowDeferredPhysicsStateCreation();
    const bool& GetbAllowDeferredPhysicsStateCreation() const;

public:
    uint8& GetbAreConstraintsDirty();
    const uint8& GetbAreConstraintsDirty() const;

public:
    uint8& GetbBegunPlay();
    const uint8& GetbBegunPlay() const;

public:
    uint32& GetbCleanedUpWorld();
    const uint32& GetbCleanedUpWorld() const;

public:
    bool& GetbCreateRenderStateForHiddenComponents();
    const bool& GetbCreateRenderStateForHiddenComponents() const;

public:
    bool& GetbDebugDrawAllTraceTags();
    const bool& GetbDebugDrawAllTraceTags() const;

public:
    uint32& GetbDebugFrameStepExecution();
    const uint32& GetbDebugFrameStepExecution() const;

public:
    uint8& GetbDebugPauseExecution();
    const uint8& GetbDebugPauseExecution() const;

public:
    uint8& GetbDoDelayedUpdateCullDistanceVolumes();
    const uint8& GetbDoDelayedUpdateCullDistanceVolumes() const;

public:
    uint8& GetbDropDetail();
    const uint8& GetbDropDetail() const;

public:
    bool& GetbHack_Force_UsesGameHiddenFlags_True();
    const bool& GetbHack_Force_UsesGameHiddenFlags_True() const;

public:
    uint8& GetbInTick();
    const uint8& GetbInTick() const;

public:
    uint8& GetbInitializedAndNeedsCleanup();
    const uint8& GetbInitializedAndNeedsCleanup() const;

public:
    uint8& GetbIsBuilt();
    const uint8& GetbIsBuilt() const;

public:
    uint8& GetbIsCameraMoveableWhenPaused();
    const uint8& GetbIsCameraMoveableWhenPaused() const;

public:
    uint8& GetbIsDefaultLevel();
    const uint8& GetbIsDefaultLevel() const;

public:
    uint8& GetbIsLevelStreamingFrozen();
    const uint8& GetbIsLevelStreamingFrozen() const;

public:
    uint8& GetbIsRunningConstructionScript();
    const uint8& GetbIsRunningConstructionScript() const;

public:
    uint8& GetbIsTearingDown();
    const uint8& GetbIsTearingDown() const;

public:
    uint8& GetbIsWorldInitialized();
    const uint8& GetbIsWorldInitialized() const;

public:
    uint8& GetbKismetScriptError();
    const uint8& GetbKismetScriptError() const;

public:
    uint32& GetbMarkedObjectsPendingKill();
    const uint32& GetbMarkedObjectsPendingKill() const;

public:
    uint8& GetbMatchStarted();
    const uint8& GetbMatchStarted() const;

public:
    uint8& GetbMaterialParameterCollectionInstanceNeedsDeferredUpdate();
    const uint8& GetbMaterialParameterCollectionInstanceNeedsDeferredUpdate() const;

public:
    bool& GetbOriginOffsetThisFrame();
    const bool& GetbOriginOffsetThisFrame() const;

public:
    uint8& GetbPlayersOnly();
    const uint8& GetbPlayersOnly() const;

public:
    uint8& GetbPlayersOnlyPending();
    const uint8& GetbPlayersOnlyPending() const;

public:
    uint8& GetbPostTickComponentUpdate();
    const uint8& GetbPostTickComponentUpdate() const;

public:
    uint8& GetbRequestedBlockOnAsyncLoading();
    const uint8& GetbRequestedBlockOnAsyncLoading() const;

public:
    uint8& GetbRequiresHitProxies();
    const uint8& GetbRequiresHitProxies() const;

public:
    bool& GetbShouldDelayGarbageCollect();
    const bool& GetbShouldDelayGarbageCollect() const;

public:
    uint8& GetbShouldForceUnloadStreamingLevels();
    const uint8& GetbShouldForceUnloadStreamingLevels() const;

public:
    uint8& GetbShouldForceVisibleStreamingLevels();
    const uint8& GetbShouldForceVisibleStreamingLevels() const;

public:
    uint8& GetbShouldSimulatePhysics();
    const uint8& GetbShouldSimulatePhysics() const;

public:
    uint8& GetbShouldTick();
    const uint8& GetbShouldTick() const;

public:
    uint8& GetbStartup();
    const uint8& GetbStartup() const;

public:
    uint8& GetbStreamingDataDirty();
    const uint8& GetbStreamingDataDirty() const;

public:
    uint8& GetbTickNewlySpawned();
    const uint8& GetbTickNewlySpawned() const;

public:
    uint8& GetbTriggerPostLoadMap();
    const uint8& GetbTriggerPostLoadMap() const;

public:
    uint8& GetbWorldWasLoadedThisTick();
    const uint8& GetbWorldWasLoadedThisTick() const;

