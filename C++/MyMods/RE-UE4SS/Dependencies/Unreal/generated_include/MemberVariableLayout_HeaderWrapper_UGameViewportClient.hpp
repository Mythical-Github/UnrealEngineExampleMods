static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    TEnumAsByte<enum ESplitScreenType::Type>& GetActiveSplitscreenType();
    const TEnumAsByte<enum ESplitScreenType::Type>& GetActiveSplitscreenType() const;

public:
    uint32& GetAudioDeviceHandle();
    const uint32& GetAudioDeviceHandle() const;

public:
    FName& GetCurrentBufferVisualizationMode();
    const FName& GetCurrentBufferVisualizationMode() const;

public:
    FName& GetCurrentGroomVisualizationMode();
    const FName& GetCurrentGroomVisualizationMode() const;

public:
    FName& GetCurrentLumenVisualizationMode();
    const FName& GetCurrentLumenVisualizationMode() const;

public:
    FName& GetCurrentNaniteVisualizationMode();
    const FName& GetCurrentNaniteVisualizationMode() const;

public:
    FName& GetCurrentStrataVisualizationMode();
    const FName& GetCurrentStrataVisualizationMode() const;

public:
    FName& GetCurrentVirtualShadowMapVisualizationMode();
    const FName& GetCurrentVirtualShadowMapVisualizationMode() const;

public:
    TArray<FDebugDisplayProperty,TSizedDefaultAllocator<32> >& GetDebugProperties();
    const TArray<FDebugDisplayProperty,TSizedDefaultAllocator<32> >& GetDebugProperties() const;

public:
    FEngineShowFlags& GetEngineShowFlags();
    const FEngineShowFlags& GetEngineShowFlags() const;

public:
    TWeakPtr<IGameLayerManager,1>& GetGameLayerManagerPtr();
    const TWeakPtr<IGameLayerManager,1>& GetGameLayerManagerPtr() const;

public:
    TWeakPtr<SWindow,1>& GetHighResScreenshotDialog();
    const TWeakPtr<SWindow,1>& GetHighResScreenshotDialog() const;

public:
    int32& GetMaxSplitscreenPlayers();
    const int32& GetMaxSplitscreenPlayers() const;

public:
    EMouseCaptureMode& GetMouseCaptureMode();
    const EMouseCaptureMode& GetMouseCaptureMode() const;

public:
    EMouseLockMode& GetMouseLockMode();
    const EMouseLockMode& GetMouseLockMode() const;

public:
    TArray<FSplitscreenData,TSizedDefaultAllocator<32> >& GetSplitscreenInfo();
    const TArray<FSplitscreenData,TSizedDefaultAllocator<32> >& GetSplitscreenInfo() const;

public:
    FStatHitchesData*& GetStatHitchesData();
    const FStatHitchesData*& GetStatHitchesData() const;

public:
    FStatUnitData*& GetStatUnitData();
    const FStatUnitData*& GetStatUnitData() const;

public:
    FTitleSafeZoneArea& GetTitleSafeZone();
    const FTitleSafeZoneArea& GetTitleSafeZone() const;

public:
    int32& GetViewModeIndex();
    const int32& GetViewModeIndex() const;

public:
    FViewport*& GetViewport();
    const FViewport*& GetViewport() const;

public:
    TObjectPtr<UConsole>& GetViewportConsole();
    const TObjectPtr<UConsole>& GetViewportConsole() const;

public:
    FViewportFrame*& GetViewportFrame();
    const FViewportFrame*& GetViewportFrame() const;

public:
    TWeakPtr<SOverlay,1>& GetViewportOverlayWidget();
    const TWeakPtr<SOverlay,1>& GetViewportOverlayWidget() const;

public:
    TWeakPtr<SWindow,1>& GetWindow();
    const TWeakPtr<SWindow,1>& GetWindow() const;

public:
    TObjectPtr<UWorld>& GetWorld();
    const TObjectPtr<UWorld>& GetWorld() const;

public:
    bool& GetbDisableSplitScreenOverride();
    const bool& GetbDisableSplitScreenOverride() const;

public:
    uint32& GetbDisableWorldRendering();
    const uint32& GetbDisableWorldRendering() const;

public:
    bool& GetbHasAudioFocus();
    const bool& GetbHasAudioFocus() const;

public:
    bool& GetbHideCursorDuringCapture();
    const bool& GetbHideCursorDuringCapture() const;

public:
    bool& GetbIgnoreInput();
    const bool& GetbIgnoreInput() const;

public:
    bool& GetbIsMouseOverClient();
    const bool& GetbIsMouseOverClient() const;

public:
    uint32& GetbIsPlayInEditorViewport();
    const uint32& GetbIsPlayInEditorViewport() const;

public:
    bool& GetbLockDuringCapture();
    const bool& GetbLockDuringCapture() const;

public:
    uint32& GetbShowTitleSafeZone();
    const uint32& GetbShowTitleSafeZone() const;

public:
    bool& GetbSuppressTransitionMessage();
    const bool& GetbSuppressTransitionMessage() const;

public:
    bool& GetbUseSoftwareCursorWidgets();
    const bool& GetbUseSoftwareCursorWidgets() const;

