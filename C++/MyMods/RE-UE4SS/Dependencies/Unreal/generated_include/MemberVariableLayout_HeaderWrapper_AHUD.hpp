static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    int32& GetCurrentTargetIndex();
    const int32& GetCurrentTargetIndex() const;

public:
    TArray<FName,TSizedDefaultAllocator<32> >& GetDebugDisplay();
    const TArray<FName,TSizedDefaultAllocator<32> >& GetDebugDisplay() const;

public:
    TArray<FDebugTextInfo,TSizedDefaultAllocator<32> >& GetDebugTextList();
    const TArray<FDebugTextInfo,TSizedDefaultAllocator<32> >& GetDebugTextList() const;

public:
    FColor& GetGreenColor();
    const FColor& GetGreenColor() const;

public:
    TArray<FHUDHitBox *,TSizedDefaultAllocator<32> >& GetHitBoxHits();
    const TArray<FHUDHitBox *,TSizedDefaultAllocator<32> >& GetHitBoxHits() const;

public:
    TArray<FHUDHitBox,TSizedDefaultAllocator<32> >& GetHitBoxMap();
    const TArray<FHUDHitBox,TSizedDefaultAllocator<32> >& GetHitBoxMap() const;

public:
    float& GetLastHUDRenderTime();
    const float& GetLastHUDRenderTime() const;

public:
    TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >& GetPostRenderedActors();
    const TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >& GetPostRenderedActors() const;

public:
    FColor& GetRedColor();
    const FColor& GetRedColor() const;

public:
    float& GetRenderDelta();
    const float& GetRenderDelta() const;

public:
    TObjectPtr<AActor>& GetShowDebugTargetActor();
    const TObjectPtr<AActor>& GetShowDebugTargetActor() const;

public:
    TSubclassOf<AActor>& GetShowDebugTargetDesiredClass();
    const TSubclassOf<AActor>& GetShowDebugTargetDesiredClass() const;

public:
    TArray<FName,TSizedDefaultAllocator<32> >& GetToggledDebugCategories();
    const TArray<FName,TSizedDefaultAllocator<32> >& GetToggledDebugCategories() const;

public:
    FColor& GetWhiteColor();
    const FColor& GetWhiteColor() const;

public:
    uint8& GetbEnableDebugTextShadow();
    const uint8& GetbEnableDebugTextShadow() const;

public:
    uint8& GetbLostFocusPaused();
    const uint8& GetbLostFocusPaused() const;

public:
    uint8& GetbShowDebugForReticleTarget();
    const uint8& GetbShowDebugForReticleTarget() const;

public:
    uint8& GetbShowDebugInfo();
    const uint8& GetbShowDebugInfo() const;

public:
    uint8& GetbShowHUD();
    const uint8& GetbShowHUD() const;

public:
    uint8& GetbShowHitBoxDebugInfo();
    const uint8& GetbShowHitBoxDebugInfo() const;

public:
    uint8& GetbShowOverlays();
    const uint8& GetbShowOverlays() const;

