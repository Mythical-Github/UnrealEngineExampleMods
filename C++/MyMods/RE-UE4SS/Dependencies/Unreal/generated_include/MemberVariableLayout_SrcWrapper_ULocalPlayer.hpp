std::unordered_map<File::StringType, int32_t> ULocalPlayer::MemberOffsets{};

TEnumAsByte<enum EAspectRatioAxisConstraint>& ULocalPlayer::GetAspectRatioAxisConstraint()
{
    static auto offset = MemberOffsets.find(STR("AspectRatioAxisConstraint"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'ULocalPlayer::AspectRatioAxisConstraint' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TEnumAsByte<enum EAspectRatioAxisConstraint>*>(this, offset->second);
}
const TEnumAsByte<enum EAspectRatioAxisConstraint>& ULocalPlayer::GetAspectRatioAxisConstraint() const
{
    static auto offset = MemberOffsets.find(STR("AspectRatioAxisConstraint"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'ULocalPlayer::AspectRatioAxisConstraint' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TEnumAsByte<enum EAspectRatioAxisConstraint>*>(this, offset->second);
}

int32& ULocalPlayer::GetControllerId()
{
    static auto offset = MemberOffsets.find(STR("ControllerId"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'ULocalPlayer::ControllerId' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& ULocalPlayer::GetControllerId() const
{
    static auto offset = MemberOffsets.find(STR("ControllerId"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'ULocalPlayer::ControllerId' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

FVector& ULocalPlayer::GetLastViewLocation()
{
    static auto offset = MemberOffsets.find(STR("LastViewLocation"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'ULocalPlayer::LastViewLocation' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FVector*>(this, offset->second);
}
const FVector& ULocalPlayer::GetLastViewLocation() const
{
    static auto offset = MemberOffsets.find(STR("LastViewLocation"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'ULocalPlayer::LastViewLocation' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FVector*>(this, offset->second);
}

TObjectPtr<UGameViewportClient>& ULocalPlayer::GetViewportClient()
{
    static auto offset = MemberOffsets.find(STR("ViewportClient"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'ULocalPlayer::ViewportClient' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TObjectPtr<UGameViewportClient>*>(this, offset->second);
}
const TObjectPtr<UGameViewportClient>& ULocalPlayer::GetViewportClient() const
{
    static auto offset = MemberOffsets.find(STR("ViewportClient"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'ULocalPlayer::ViewportClient' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TObjectPtr<UGameViewportClient>*>(this, offset->second);
}

uint32& ULocalPlayer::GetbSentSplitJoin()
{
    static auto offset = MemberOffsets.find(STR("bSentSplitJoin"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'ULocalPlayer::bSentSplitJoin' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& ULocalPlayer::GetbSentSplitJoin() const
{
    static auto offset = MemberOffsets.find(STR("bSentSplitJoin"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'ULocalPlayer::bSentSplitJoin' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

