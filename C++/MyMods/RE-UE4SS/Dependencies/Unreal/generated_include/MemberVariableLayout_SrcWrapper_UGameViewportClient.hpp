std::unordered_map<File::StringType, int32_t> UGameViewportClient::MemberOffsets{};

TEnumAsByte<enum ESplitScreenType::Type>& UGameViewportClient::GetActiveSplitscreenType()
{
    static auto offset = MemberOffsets.find(STR("ActiveSplitscreenType"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::ActiveSplitscreenType' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TEnumAsByte<enum ESplitScreenType::Type>*>(this, offset->second);
}
const TEnumAsByte<enum ESplitScreenType::Type>& UGameViewportClient::GetActiveSplitscreenType() const
{
    static auto offset = MemberOffsets.find(STR("ActiveSplitscreenType"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::ActiveSplitscreenType' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TEnumAsByte<enum ESplitScreenType::Type>*>(this, offset->second);
}

uint32& UGameViewportClient::GetAudioDeviceHandle()
{
    static auto offset = MemberOffsets.find(STR("AudioDeviceHandle"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::AudioDeviceHandle' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UGameViewportClient::GetAudioDeviceHandle() const
{
    static auto offset = MemberOffsets.find(STR("AudioDeviceHandle"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::AudioDeviceHandle' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

FName& UGameViewportClient::GetCurrentBufferVisualizationMode()
{
    static auto offset = MemberOffsets.find(STR("CurrentBufferVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentBufferVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& UGameViewportClient::GetCurrentBufferVisualizationMode() const
{
    static auto offset = MemberOffsets.find(STR("CurrentBufferVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentBufferVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

FName& UGameViewportClient::GetCurrentGroomVisualizationMode()
{
    static auto offset = MemberOffsets.find(STR("CurrentGroomVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentGroomVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& UGameViewportClient::GetCurrentGroomVisualizationMode() const
{
    static auto offset = MemberOffsets.find(STR("CurrentGroomVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentGroomVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

FName& UGameViewportClient::GetCurrentLumenVisualizationMode()
{
    static auto offset = MemberOffsets.find(STR("CurrentLumenVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentLumenVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& UGameViewportClient::GetCurrentLumenVisualizationMode() const
{
    static auto offset = MemberOffsets.find(STR("CurrentLumenVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentLumenVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

FName& UGameViewportClient::GetCurrentNaniteVisualizationMode()
{
    static auto offset = MemberOffsets.find(STR("CurrentNaniteVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentNaniteVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& UGameViewportClient::GetCurrentNaniteVisualizationMode() const
{
    static auto offset = MemberOffsets.find(STR("CurrentNaniteVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentNaniteVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

FName& UGameViewportClient::GetCurrentStrataVisualizationMode()
{
    static auto offset = MemberOffsets.find(STR("CurrentStrataVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentStrataVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& UGameViewportClient::GetCurrentStrataVisualizationMode() const
{
    static auto offset = MemberOffsets.find(STR("CurrentStrataVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentStrataVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

FName& UGameViewportClient::GetCurrentVirtualShadowMapVisualizationMode()
{
    static auto offset = MemberOffsets.find(STR("CurrentVirtualShadowMapVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentVirtualShadowMapVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& UGameViewportClient::GetCurrentVirtualShadowMapVisualizationMode() const
{
    static auto offset = MemberOffsets.find(STR("CurrentVirtualShadowMapVisualizationMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::CurrentVirtualShadowMapVisualizationMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

TArray<FDebugDisplayProperty,TSizedDefaultAllocator<32> >& UGameViewportClient::GetDebugProperties()
{
    static auto offset = MemberOffsets.find(STR("DebugProperties"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::DebugProperties' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FDebugDisplayProperty,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FDebugDisplayProperty,TSizedDefaultAllocator<32> >& UGameViewportClient::GetDebugProperties() const
{
    static auto offset = MemberOffsets.find(STR("DebugProperties"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::DebugProperties' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FDebugDisplayProperty,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

FEngineShowFlags& UGameViewportClient::GetEngineShowFlags()
{
    static auto offset = MemberOffsets.find(STR("EngineShowFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::EngineShowFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FEngineShowFlags*>(this, offset->second);
}
const FEngineShowFlags& UGameViewportClient::GetEngineShowFlags() const
{
    static auto offset = MemberOffsets.find(STR("EngineShowFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::EngineShowFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FEngineShowFlags*>(this, offset->second);
}

TWeakPtr<IGameLayerManager,1>& UGameViewportClient::GetGameLayerManagerPtr()
{
    static auto offset = MemberOffsets.find(STR("GameLayerManagerPtr"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::GameLayerManagerPtr' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TWeakPtr<IGameLayerManager,1>*>(this, offset->second);
}
const TWeakPtr<IGameLayerManager,1>& UGameViewportClient::GetGameLayerManagerPtr() const
{
    static auto offset = MemberOffsets.find(STR("GameLayerManagerPtr"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::GameLayerManagerPtr' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TWeakPtr<IGameLayerManager,1>*>(this, offset->second);
}

TWeakPtr<SWindow,1>& UGameViewportClient::GetHighResScreenshotDialog()
{
    static auto offset = MemberOffsets.find(STR("HighResScreenshotDialog"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::HighResScreenshotDialog' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TWeakPtr<SWindow,1>*>(this, offset->second);
}
const TWeakPtr<SWindow,1>& UGameViewportClient::GetHighResScreenshotDialog() const
{
    static auto offset = MemberOffsets.find(STR("HighResScreenshotDialog"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::HighResScreenshotDialog' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TWeakPtr<SWindow,1>*>(this, offset->second);
}

int32& UGameViewportClient::GetMaxSplitscreenPlayers()
{
    static auto offset = MemberOffsets.find(STR("MaxSplitscreenPlayers"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::MaxSplitscreenPlayers' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UGameViewportClient::GetMaxSplitscreenPlayers() const
{
    static auto offset = MemberOffsets.find(STR("MaxSplitscreenPlayers"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::MaxSplitscreenPlayers' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

EMouseCaptureMode& UGameViewportClient::GetMouseCaptureMode()
{
    static auto offset = MemberOffsets.find(STR("MouseCaptureMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::MouseCaptureMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<EMouseCaptureMode*>(this, offset->second);
}
const EMouseCaptureMode& UGameViewportClient::GetMouseCaptureMode() const
{
    static auto offset = MemberOffsets.find(STR("MouseCaptureMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::MouseCaptureMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const EMouseCaptureMode*>(this, offset->second);
}

EMouseLockMode& UGameViewportClient::GetMouseLockMode()
{
    static auto offset = MemberOffsets.find(STR("MouseLockMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::MouseLockMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<EMouseLockMode*>(this, offset->second);
}
const EMouseLockMode& UGameViewportClient::GetMouseLockMode() const
{
    static auto offset = MemberOffsets.find(STR("MouseLockMode"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::MouseLockMode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const EMouseLockMode*>(this, offset->second);
}

TArray<FSplitscreenData,TSizedDefaultAllocator<32> >& UGameViewportClient::GetSplitscreenInfo()
{
    static auto offset = MemberOffsets.find(STR("SplitscreenInfo"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::SplitscreenInfo' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FSplitscreenData,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FSplitscreenData,TSizedDefaultAllocator<32> >& UGameViewportClient::GetSplitscreenInfo() const
{
    static auto offset = MemberOffsets.find(STR("SplitscreenInfo"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::SplitscreenInfo' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FSplitscreenData,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

FStatHitchesData*& UGameViewportClient::GetStatHitchesData()
{
    static auto offset = MemberOffsets.find(STR("StatHitchesData"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::StatHitchesData' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FStatHitchesData**>(this, offset->second);
}
const FStatHitchesData*& UGameViewportClient::GetStatHitchesData() const
{
    static auto offset = MemberOffsets.find(STR("StatHitchesData"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::StatHitchesData' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FStatHitchesData**>(this, offset->second);
}

FStatUnitData*& UGameViewportClient::GetStatUnitData()
{
    static auto offset = MemberOffsets.find(STR("StatUnitData"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::StatUnitData' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FStatUnitData**>(this, offset->second);
}
const FStatUnitData*& UGameViewportClient::GetStatUnitData() const
{
    static auto offset = MemberOffsets.find(STR("StatUnitData"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::StatUnitData' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FStatUnitData**>(this, offset->second);
}

FTitleSafeZoneArea& UGameViewportClient::GetTitleSafeZone()
{
    static auto offset = MemberOffsets.find(STR("TitleSafeZone"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::TitleSafeZone' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FTitleSafeZoneArea*>(this, offset->second);
}
const FTitleSafeZoneArea& UGameViewportClient::GetTitleSafeZone() const
{
    static auto offset = MemberOffsets.find(STR("TitleSafeZone"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::TitleSafeZone' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FTitleSafeZoneArea*>(this, offset->second);
}

int32& UGameViewportClient::GetViewModeIndex()
{
    static auto offset = MemberOffsets.find(STR("ViewModeIndex"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::ViewModeIndex' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UGameViewportClient::GetViewModeIndex() const
{
    static auto offset = MemberOffsets.find(STR("ViewModeIndex"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::ViewModeIndex' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

FViewport*& UGameViewportClient::GetViewport()
{
    static auto offset = MemberOffsets.find(STR("Viewport"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::Viewport' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FViewport**>(this, offset->second);
}
const FViewport*& UGameViewportClient::GetViewport() const
{
    static auto offset = MemberOffsets.find(STR("Viewport"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::Viewport' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FViewport**>(this, offset->second);
}

TObjectPtr<UConsole>& UGameViewportClient::GetViewportConsole()
{
    static auto offset = MemberOffsets.find(STR("ViewportConsole"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::ViewportConsole' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TObjectPtr<UConsole>*>(this, offset->second);
}
const TObjectPtr<UConsole>& UGameViewportClient::GetViewportConsole() const
{
    static auto offset = MemberOffsets.find(STR("ViewportConsole"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::ViewportConsole' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TObjectPtr<UConsole>*>(this, offset->second);
}

FViewportFrame*& UGameViewportClient::GetViewportFrame()
{
    static auto offset = MemberOffsets.find(STR("ViewportFrame"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::ViewportFrame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FViewportFrame**>(this, offset->second);
}
const FViewportFrame*& UGameViewportClient::GetViewportFrame() const
{
    static auto offset = MemberOffsets.find(STR("ViewportFrame"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::ViewportFrame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FViewportFrame**>(this, offset->second);
}

TWeakPtr<SOverlay,1>& UGameViewportClient::GetViewportOverlayWidget()
{
    static auto offset = MemberOffsets.find(STR("ViewportOverlayWidget"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::ViewportOverlayWidget' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TWeakPtr<SOverlay,1>*>(this, offset->second);
}
const TWeakPtr<SOverlay,1>& UGameViewportClient::GetViewportOverlayWidget() const
{
    static auto offset = MemberOffsets.find(STR("ViewportOverlayWidget"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::ViewportOverlayWidget' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TWeakPtr<SOverlay,1>*>(this, offset->second);
}

TWeakPtr<SWindow,1>& UGameViewportClient::GetWindow()
{
    static auto offset = MemberOffsets.find(STR("Window"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::Window' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TWeakPtr<SWindow,1>*>(this, offset->second);
}
const TWeakPtr<SWindow,1>& UGameViewportClient::GetWindow() const
{
    static auto offset = MemberOffsets.find(STR("Window"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::Window' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TWeakPtr<SWindow,1>*>(this, offset->second);
}

TObjectPtr<UWorld>& UGameViewportClient::GetWorld()
{
    static auto offset = MemberOffsets.find(STR("World"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::World' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TObjectPtr<UWorld>*>(this, offset->second);
}
const TObjectPtr<UWorld>& UGameViewportClient::GetWorld() const
{
    static auto offset = MemberOffsets.find(STR("World"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::World' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TObjectPtr<UWorld>*>(this, offset->second);
}

bool& UGameViewportClient::GetbDisableSplitScreenOverride()
{
    static auto offset = MemberOffsets.find(STR("bDisableSplitScreenOverride"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bDisableSplitScreenOverride' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UGameViewportClient::GetbDisableSplitScreenOverride() const
{
    static auto offset = MemberOffsets.find(STR("bDisableSplitScreenOverride"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bDisableSplitScreenOverride' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

uint32& UGameViewportClient::GetbDisableWorldRendering()
{
    static auto offset = MemberOffsets.find(STR("bDisableWorldRendering"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bDisableWorldRendering' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UGameViewportClient::GetbDisableWorldRendering() const
{
    static auto offset = MemberOffsets.find(STR("bDisableWorldRendering"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bDisableWorldRendering' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

bool& UGameViewportClient::GetbHasAudioFocus()
{
    static auto offset = MemberOffsets.find(STR("bHasAudioFocus"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bHasAudioFocus' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UGameViewportClient::GetbHasAudioFocus() const
{
    static auto offset = MemberOffsets.find(STR("bHasAudioFocus"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bHasAudioFocus' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

bool& UGameViewportClient::GetbHideCursorDuringCapture()
{
    static auto offset = MemberOffsets.find(STR("bHideCursorDuringCapture"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bHideCursorDuringCapture' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UGameViewportClient::GetbHideCursorDuringCapture() const
{
    static auto offset = MemberOffsets.find(STR("bHideCursorDuringCapture"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bHideCursorDuringCapture' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

bool& UGameViewportClient::GetbIgnoreInput()
{
    static auto offset = MemberOffsets.find(STR("bIgnoreInput"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bIgnoreInput' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UGameViewportClient::GetbIgnoreInput() const
{
    static auto offset = MemberOffsets.find(STR("bIgnoreInput"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bIgnoreInput' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

bool& UGameViewportClient::GetbIsMouseOverClient()
{
    static auto offset = MemberOffsets.find(STR("bIsMouseOverClient"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bIsMouseOverClient' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UGameViewportClient::GetbIsMouseOverClient() const
{
    static auto offset = MemberOffsets.find(STR("bIsMouseOverClient"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bIsMouseOverClient' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

uint32& UGameViewportClient::GetbIsPlayInEditorViewport()
{
    static auto offset = MemberOffsets.find(STR("bIsPlayInEditorViewport"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bIsPlayInEditorViewport' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UGameViewportClient::GetbIsPlayInEditorViewport() const
{
    static auto offset = MemberOffsets.find(STR("bIsPlayInEditorViewport"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bIsPlayInEditorViewport' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

bool& UGameViewportClient::GetbLockDuringCapture()
{
    static auto offset = MemberOffsets.find(STR("bLockDuringCapture"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bLockDuringCapture' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UGameViewportClient::GetbLockDuringCapture() const
{
    static auto offset = MemberOffsets.find(STR("bLockDuringCapture"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bLockDuringCapture' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

uint32& UGameViewportClient::GetbShowTitleSafeZone()
{
    static auto offset = MemberOffsets.find(STR("bShowTitleSafeZone"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bShowTitleSafeZone' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& UGameViewportClient::GetbShowTitleSafeZone() const
{
    static auto offset = MemberOffsets.find(STR("bShowTitleSafeZone"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bShowTitleSafeZone' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

bool& UGameViewportClient::GetbSuppressTransitionMessage()
{
    static auto offset = MemberOffsets.find(STR("bSuppressTransitionMessage"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bSuppressTransitionMessage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UGameViewportClient::GetbSuppressTransitionMessage() const
{
    static auto offset = MemberOffsets.find(STR("bSuppressTransitionMessage"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bSuppressTransitionMessage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

bool& UGameViewportClient::GetbUseSoftwareCursorWidgets()
{
    static auto offset = MemberOffsets.find(STR("bUseSoftwareCursorWidgets"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bUseSoftwareCursorWidgets' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UGameViewportClient::GetbUseSoftwareCursorWidgets() const
{
    static auto offset = MemberOffsets.find(STR("bUseSoftwareCursorWidgets"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UGameViewportClient::bUseSoftwareCursorWidgets' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

