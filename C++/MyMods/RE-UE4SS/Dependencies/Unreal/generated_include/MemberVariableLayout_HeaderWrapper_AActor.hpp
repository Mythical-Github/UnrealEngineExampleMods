static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    AActor::EActorBeginPlayState& GetActorHasBegunPlay();
    const AActor::EActorBeginPlayState& GetActorHasBegunPlay() const;

public:
    FRepAttachment& GetAttachmentReplication();
    const FRepAttachment& GetAttachmentReplication() const;

public:
    TEnumAsByte<enum EAutoReceiveInput::Type>& GetAutoReceiveInput();
    const TEnumAsByte<enum EAutoReceiveInput::Type>& GetAutoReceiveInput() const;

public:
    float& GetCachedLastRenderTime();
    const float& GetCachedLastRenderTime() const;

public:
    TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >& GetChildren();
    const TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >& GetChildren() const;

public:
    TArray<AMatineeActor *,TSizedDefaultAllocator<32> >& GetControllingMatineeActors();
    const TArray<AMatineeActor *,TSizedDefaultAllocator<32> >& GetControllingMatineeActors() const;

public:
    float& GetCreationTime();
    const float& GetCreationTime() const;

public:
    float& GetCustomTimeDilation();
    const float& GetCustomTimeDilation() const;

public:
    EActorUpdateOverlapsMethod& GetDefaultUpdateOverlapsMethodDuringLevelStreaming();
    const EActorUpdateOverlapsMethod& GetDefaultUpdateOverlapsMethodDuringLevelStreaming() const;

public:
    FRenderCommandFence& GetDetachFence();
    const FRenderCommandFence& GetDetachFence() const;

public:
    uint64& GetHiddenEditorViews();
    const uint64& GetHiddenEditorViews() const;

public:
    float& GetInitialLifeSpan();
    const float& GetInitialLifeSpan() const;

public:
    TObjectPtr<UInputComponent>& GetInputComponent();
    const TObjectPtr<UInputComponent>& GetInputComponent() const;

public:
    TEnumAsByte<enum EInputConsumeOptions>& GetInputConsumeOption_DEPRECATED();
    const TEnumAsByte<enum EInputConsumeOptions>& GetInputConsumeOption_DEPRECATED() const;

public:
    int32& GetInputPriority();
    const int32& GetInputPriority() const;

public:
    float& GetLastNetUpdateTime();
    const float& GetLastNetUpdateTime() const;

public:
    float& GetLastRenderTime();
    const float& GetLastRenderTime() const;

public:
    TArray<FName,TSizedDefaultAllocator<32> >& GetLayers();
    const TArray<FName,TSizedDefaultAllocator<32> >& GetLayers() const;

public:
    float& GetMinNetUpdateFrequency();
    const float& GetMinNetUpdateFrequency() const;

public:
    float& GetNetCullDistanceSquared();
    const float& GetNetCullDistanceSquared() const;

public:
    TEnumAsByte<enum ENetDormancy>& GetNetDormancy();
    const TEnumAsByte<enum ENetDormancy>& GetNetDormancy() const;

public:
    FName& GetNetDriverName();
    const FName& GetNetDriverName() const;

public:
    float& GetNetPriority();
    const float& GetNetPriority() const;

public:
    int32& GetNetTag();
    const int32& GetNetTag() const;

public:
    float& GetNetUpdateFrequency();
    const float& GetNetUpdateFrequency() const;

public:
    float& GetNetUpdateTime();
    const float& GetNetUpdateTime() const;

public:
    FActorBeginOverlapSignature& GetOnActorBeginOverlap();
    const FActorBeginOverlapSignature& GetOnActorBeginOverlap() const;

public:
    FActorEndOverlapSignature& GetOnActorEndOverlap();
    const FActorEndOverlapSignature& GetOnActorEndOverlap() const;

public:
    FActorHitSignature& GetOnActorHit();
    const FActorHitSignature& GetOnActorHit() const;

public:
    FActorBeginCursorOverSignature& GetOnBeginCursorOver();
    const FActorBeginCursorOverSignature& GetOnBeginCursorOver() const;

public:
    FActorOnClickedSignature& GetOnClicked();
    const FActorOnClickedSignature& GetOnClicked() const;

public:
    FActorDestroyedSignature& GetOnDestroyed();
    const FActorDestroyedSignature& GetOnDestroyed() const;

public:
    FActorEndCursorOverSignature& GetOnEndCursorOver();
    const FActorEndCursorOverSignature& GetOnEndCursorOver() const;

public:
    FActorEndPlaySignature& GetOnEndPlay();
    const FActorEndPlaySignature& GetOnEndPlay() const;

public:
    FActorOnInputTouchBeginSignature& GetOnInputTouchBegin();
    const FActorOnInputTouchBeginSignature& GetOnInputTouchBegin() const;

public:
    FActorOnInputTouchEndSignature& GetOnInputTouchEnd();
    const FActorOnInputTouchEndSignature& GetOnInputTouchEnd() const;

public:
    FActorBeginTouchOverSignature& GetOnInputTouchEnter();
    const FActorBeginTouchOverSignature& GetOnInputTouchEnter() const;

public:
    FActorEndTouchOverSignature& GetOnInputTouchLeave();
    const FActorEndTouchOverSignature& GetOnInputTouchLeave() const;

public:
    FActorOnReleasedSignature& GetOnReleased();
    const FActorOnReleasedSignature& GetOnReleased() const;

public:
    FTakeAnyDamageSignature& GetOnTakeAnyDamage();
    const FTakeAnyDamageSignature& GetOnTakeAnyDamage() const;

public:
    FTakePointDamageSignature& GetOnTakePointDamage();
    const FTakePointDamageSignature& GetOnTakePointDamage() const;

public:
    FTakeRadialDamageSignature& GetOnTakeRadialDamage();
    const FTakeRadialDamageSignature& GetOnTakeRadialDamage() const;

public:
    TObjectPtr<AActor>& GetOwner();
    const TObjectPtr<AActor>& GetOwner() const;

public:
    TWeakObjectPtr<UChildActorComponent,FWeakObjectPtr>& GetParentComponent();
    const TWeakObjectPtr<UChildActorComponent,FWeakObjectPtr>& GetParentComponent() const;

public:
    TWeakObjectPtr<AActor,FWeakObjectPtr>& GetParentComponentActor_DEPRECATED();
    const TWeakObjectPtr<AActor,FWeakObjectPtr>& GetParentComponentActor_DEPRECATED() const;

public:
    FActorTickFunction& GetPrimaryActorTick();
    const FActorTickFunction& GetPrimaryActorTick() const;

public:
    int32& GetRayTracingGroupId();
    const int32& GetRayTracingGroupId() const;

public:
    TEnumAsByte<enum ENetRole>& GetRemoteRole();
    const TEnumAsByte<enum ENetRole>& GetRemoteRole() const;

public:
    TArray<UE::Net::FReplicatedComponentInfo,TSizedDefaultAllocator<32> >& GetReplicatedComponentsInfo();
    const TArray<UE::Net::FReplicatedComponentInfo,TSizedDefaultAllocator<32> >& GetReplicatedComponentsInfo() const;

public:
    FRepMovement& GetReplicatedMovement();
    const FRepMovement& GetReplicatedMovement() const;

public:
    UE::Net::FSubObjectRegistry& GetReplicatedSubObjects();
    const UE::Net::FSubObjectRegistry& GetReplicatedSubObjects() const;

public:
    TEnumAsByte<enum ENetRole>& GetRole();
    const TEnumAsByte<enum ENetRole>& GetRole() const;

public:
    TObjectPtr<USceneComponent>& GetRootComponent();
    const TObjectPtr<USceneComponent>& GetRootComponent() const;

public:
    ESpawnActorCollisionHandlingMethod& GetSpawnCollisionHandlingMethod();
    const ESpawnActorCollisionHandlingMethod& GetSpawnCollisionHandlingMethod() const;

public:
    TArray<FName,TSizedDefaultAllocator<32> >& GetTags();
    const TArray<FName,TSizedDefaultAllocator<32> >& GetTags() const;

public:
    FTimerHandle& GetTimerHandle_LifeSpanExpired();
    const FTimerHandle& GetTimerHandle_LifeSpanExpired() const;

public:
    EActorUpdateOverlapsMethod& GetUpdateOverlapsMethodDuringLevelStreaming();
    const EActorUpdateOverlapsMethod& GetUpdateOverlapsMethodDuringLevelStreaming() const;

public:
    uint8& GetbActorBeginningPlayFromLevelStreaming();
    const uint8& GetbActorBeginningPlayFromLevelStreaming() const;

public:
    uint8& GetbActorEnableCollision();
    const uint8& GetbActorEnableCollision() const;

public:
    uint8& GetbActorInitialized();
    const uint8& GetbActorInitialized() const;

public:
    uint8& GetbActorIsBeingConstructed();
    const uint8& GetbActorIsBeingConstructed() const;

public:
    uint8& GetbActorIsBeingDestroyed();
    const uint8& GetbActorIsBeingDestroyed() const;

public:
    uint8& GetbActorSeamlessTraveled();
    const uint8& GetbActorSeamlessTraveled() const;

public:
    uint8& GetbActorWantsDestroyDuringBeginPlay();
    const uint8& GetbActorWantsDestroyDuringBeginPlay() const;

public:
    uint8& GetbAllowReceiveTickEventOnDedicatedServer();
    const uint8& GetbAllowReceiveTickEventOnDedicatedServer() const;

public:
    uint8& GetbAllowTickBeforeBeginPlay();
    const uint8& GetbAllowTickBeforeBeginPlay() const;

public:
    uint8& GetbAlwaysRelevant();
    const uint8& GetbAlwaysRelevant() const;

public:
    uint8& GetbAsyncPhysicsTickEnabled();
    const uint8& GetbAsyncPhysicsTickEnabled() const;

public:
    uint8& GetbAutoDestroyWhenFinished();
    const uint8& GetbAutoDestroyWhenFinished() const;

public:
    uint8& GetbBlockInput();
    const uint8& GetbBlockInput() const;

public:
    uint8& GetbCallPreReplication();
    const uint8& GetbCallPreReplication() const;

public:
    uint8& GetbCallPreReplicationForReplay();
    const uint8& GetbCallPreReplicationForReplay() const;

public:
    uint8& GetbCanBeDamaged();
    const uint8& GetbCanBeDamaged() const;

public:
    uint8& GetbCanBeInCluster();
    const uint8& GetbCanBeInCluster() const;

public:
    uint8& GetbCollideWhenPlacing();
    const uint8& GetbCollideWhenPlacing() const;

public:
    uint8& GetbEnableAutoLODGeneration();
    const uint8& GetbEnableAutoLODGeneration() const;

public:
    uint8& GetbExchangedRoles();
    const uint8& GetbExchangedRoles() const;

public:
    uint8& GetbFindCameraComponentWhenViewTarget();
    const uint8& GetbFindCameraComponentWhenViewTarget() const;

public:
    uint8& GetbForceNetAddressable();
    const uint8& GetbForceNetAddressable() const;

public:
    uint8& GetbGenerateOverlapEventsDuringLevelStreaming();
    const uint8& GetbGenerateOverlapEventsDuringLevelStreaming() const;

public:
    uint8& GetbHasDeferredComponentRegistration();
    const uint8& GetbHasDeferredComponentRegistration() const;

public:
    uint8& GetbHasFinishedSpawning();
    const uint8& GetbHasFinishedSpawning() const;

public:
    uint8& GetbHasRegisteredAllComponents();
    const uint8& GetbHasRegisteredAllComponents() const;

public:
    uint8& GetbHidden();
    const uint8& GetbHidden() const;

public:
    uint8& GetbIgnoresOriginShifting();
    const uint8& GetbIgnoresOriginShifting() const;

public:
    uint8& GetbIsEditorOnlyActor();
    const uint8& GetbIsEditorOnlyActor() const;

public:
    uint8& GetbNetCheckedInitialPhysicsState();
    const uint8& GetbNetCheckedInitialPhysicsState() const;

public:
    uint8& GetbNetLoadOnClient();
    const uint8& GetbNetLoadOnClient() const;

public:
    uint8& GetbNetStartup();
    const uint8& GetbNetStartup() const;

public:
    uint8& GetbNetTemporary();
    const uint8& GetbNetTemporary() const;

public:
    uint8& GetbNetUseOwnerRelevancy();
    const uint8& GetbNetUseOwnerRelevancy() const;

public:
    uint8& GetbOnlyRelevantToOwner();
    const uint8& GetbOnlyRelevantToOwner() const;

public:
    uint8& GetbPendingNetUpdate();
    const uint8& GetbPendingNetUpdate() const;

public:
    uint8& GetbRelevantForLevelBounds();
    const uint8& GetbRelevantForLevelBounds() const;

public:
    uint8& GetbRelevantForNetworkReplays();
    const uint8& GetbRelevantForNetworkReplays() const;

public:
    uint8& GetbReplayRewindable();
    const uint8& GetbReplayRewindable() const;

public:
    uint8& GetbReplicateMovement();
    const uint8& GetbReplicateMovement() const;

public:
    uint8& GetbReplicateUsingRegisteredSubObjectList();
    const uint8& GetbReplicateUsingRegisteredSubObjectList() const;

public:
    uint8& GetbReplicates();
    const uint8& GetbReplicates() const;

public:
    uint8& GetbRunningUserConstructionScript();
    const uint8& GetbRunningUserConstructionScript() const;

public:
    uint8& GetbTearOff();
    const uint8& GetbTearOff() const;

public:
    uint8& GetbTickFunctionsRegistered();
    const uint8& GetbTickFunctionsRegistered() const;

