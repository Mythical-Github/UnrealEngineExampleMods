std::unordered_map<File::StringType, int32_t> AHUD::MemberOffsets{};

int32& AHUD::GetCurrentTargetIndex()
{
    static auto offset = MemberOffsets.find(STR("CurrentTargetIndex"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::CurrentTargetIndex' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& AHUD::GetCurrentTargetIndex() const
{
    static auto offset = MemberOffsets.find(STR("CurrentTargetIndex"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::CurrentTargetIndex' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

TArray<FName,TSizedDefaultAllocator<32> >& AHUD::GetDebugDisplay()
{
    static auto offset = MemberOffsets.find(STR("DebugDisplay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::DebugDisplay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FName,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FName,TSizedDefaultAllocator<32> >& AHUD::GetDebugDisplay() const
{
    static auto offset = MemberOffsets.find(STR("DebugDisplay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::DebugDisplay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FName,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

TArray<FDebugTextInfo,TSizedDefaultAllocator<32> >& AHUD::GetDebugTextList()
{
    static auto offset = MemberOffsets.find(STR("DebugTextList"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::DebugTextList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FDebugTextInfo,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FDebugTextInfo,TSizedDefaultAllocator<32> >& AHUD::GetDebugTextList() const
{
    static auto offset = MemberOffsets.find(STR("DebugTextList"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::DebugTextList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FDebugTextInfo,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

FColor& AHUD::GetGreenColor()
{
    static auto offset = MemberOffsets.find(STR("GreenColor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::GreenColor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FColor*>(this, offset->second);
}
const FColor& AHUD::GetGreenColor() const
{
    static auto offset = MemberOffsets.find(STR("GreenColor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::GreenColor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FColor*>(this, offset->second);
}

TArray<FHUDHitBox *,TSizedDefaultAllocator<32> >& AHUD::GetHitBoxHits()
{
    static auto offset = MemberOffsets.find(STR("HitBoxHits"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::HitBoxHits' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FHUDHitBox *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FHUDHitBox *,TSizedDefaultAllocator<32> >& AHUD::GetHitBoxHits() const
{
    static auto offset = MemberOffsets.find(STR("HitBoxHits"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::HitBoxHits' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FHUDHitBox *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

TArray<FHUDHitBox,TSizedDefaultAllocator<32> >& AHUD::GetHitBoxMap()
{
    static auto offset = MemberOffsets.find(STR("HitBoxMap"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::HitBoxMap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FHUDHitBox,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FHUDHitBox,TSizedDefaultAllocator<32> >& AHUD::GetHitBoxMap() const
{
    static auto offset = MemberOffsets.find(STR("HitBoxMap"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::HitBoxMap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FHUDHitBox,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

float& AHUD::GetLastHUDRenderTime()
{
    static auto offset = MemberOffsets.find(STR("LastHUDRenderTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::LastHUDRenderTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AHUD::GetLastHUDRenderTime() const
{
    static auto offset = MemberOffsets.find(STR("LastHUDRenderTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::LastHUDRenderTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >& AHUD::GetPostRenderedActors()
{
    static auto offset = MemberOffsets.find(STR("PostRenderedActors"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::PostRenderedActors' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >& AHUD::GetPostRenderedActors() const
{
    static auto offset = MemberOffsets.find(STR("PostRenderedActors"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::PostRenderedActors' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

FColor& AHUD::GetRedColor()
{
    static auto offset = MemberOffsets.find(STR("RedColor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::RedColor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FColor*>(this, offset->second);
}
const FColor& AHUD::GetRedColor() const
{
    static auto offset = MemberOffsets.find(STR("RedColor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::RedColor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FColor*>(this, offset->second);
}

float& AHUD::GetRenderDelta()
{
    static auto offset = MemberOffsets.find(STR("RenderDelta"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::RenderDelta' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AHUD::GetRenderDelta() const
{
    static auto offset = MemberOffsets.find(STR("RenderDelta"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::RenderDelta' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

TObjectPtr<AActor>& AHUD::GetShowDebugTargetActor()
{
    static auto offset = MemberOffsets.find(STR("ShowDebugTargetActor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::ShowDebugTargetActor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TObjectPtr<AActor>*>(this, offset->second);
}
const TObjectPtr<AActor>& AHUD::GetShowDebugTargetActor() const
{
    static auto offset = MemberOffsets.find(STR("ShowDebugTargetActor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::ShowDebugTargetActor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TObjectPtr<AActor>*>(this, offset->second);
}

TSubclassOf<AActor>& AHUD::GetShowDebugTargetDesiredClass()
{
    static auto offset = MemberOffsets.find(STR("ShowDebugTargetDesiredClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::ShowDebugTargetDesiredClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TSubclassOf<AActor>*>(this, offset->second);
}
const TSubclassOf<AActor>& AHUD::GetShowDebugTargetDesiredClass() const
{
    static auto offset = MemberOffsets.find(STR("ShowDebugTargetDesiredClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::ShowDebugTargetDesiredClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TSubclassOf<AActor>*>(this, offset->second);
}

TArray<FName,TSizedDefaultAllocator<32> >& AHUD::GetToggledDebugCategories()
{
    static auto offset = MemberOffsets.find(STR("ToggledDebugCategories"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::ToggledDebugCategories' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FName,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FName,TSizedDefaultAllocator<32> >& AHUD::GetToggledDebugCategories() const
{
    static auto offset = MemberOffsets.find(STR("ToggledDebugCategories"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::ToggledDebugCategories' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FName,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

FColor& AHUD::GetWhiteColor()
{
    static auto offset = MemberOffsets.find(STR("WhiteColor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::WhiteColor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FColor*>(this, offset->second);
}
const FColor& AHUD::GetWhiteColor() const
{
    static auto offset = MemberOffsets.find(STR("WhiteColor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::WhiteColor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FColor*>(this, offset->second);
}

uint8& AHUD::GetbEnableDebugTextShadow()
{
    static auto offset = MemberOffsets.find(STR("bEnableDebugTextShadow"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bEnableDebugTextShadow' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AHUD::GetbEnableDebugTextShadow() const
{
    static auto offset = MemberOffsets.find(STR("bEnableDebugTextShadow"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bEnableDebugTextShadow' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AHUD::GetbLostFocusPaused()
{
    static auto offset = MemberOffsets.find(STR("bLostFocusPaused"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bLostFocusPaused' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AHUD::GetbLostFocusPaused() const
{
    static auto offset = MemberOffsets.find(STR("bLostFocusPaused"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bLostFocusPaused' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AHUD::GetbShowDebugForReticleTarget()
{
    static auto offset = MemberOffsets.find(STR("bShowDebugForReticleTarget"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bShowDebugForReticleTarget' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AHUD::GetbShowDebugForReticleTarget() const
{
    static auto offset = MemberOffsets.find(STR("bShowDebugForReticleTarget"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bShowDebugForReticleTarget' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AHUD::GetbShowDebugInfo()
{
    static auto offset = MemberOffsets.find(STR("bShowDebugInfo"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bShowDebugInfo' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AHUD::GetbShowDebugInfo() const
{
    static auto offset = MemberOffsets.find(STR("bShowDebugInfo"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bShowDebugInfo' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AHUD::GetbShowHUD()
{
    static auto offset = MemberOffsets.find(STR("bShowHUD"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bShowHUD' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AHUD::GetbShowHUD() const
{
    static auto offset = MemberOffsets.find(STR("bShowHUD"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bShowHUD' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AHUD::GetbShowHitBoxDebugInfo()
{
    static auto offset = MemberOffsets.find(STR("bShowHitBoxDebugInfo"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bShowHitBoxDebugInfo' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AHUD::GetbShowHitBoxDebugInfo() const
{
    static auto offset = MemberOffsets.find(STR("bShowHitBoxDebugInfo"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bShowHitBoxDebugInfo' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AHUD::GetbShowOverlays()
{
    static auto offset = MemberOffsets.find(STR("bShowOverlays"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bShowOverlays' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AHUD::GetbShowOverlays() const
{
    static auto offset = MemberOffsets.find(STR("bShowOverlays"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AHUD::bShowOverlays' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

