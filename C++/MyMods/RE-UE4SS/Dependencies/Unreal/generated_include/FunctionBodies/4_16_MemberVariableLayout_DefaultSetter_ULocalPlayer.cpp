if (auto it = ULocalPlayer::MemberOffsets.find(STR("AspectRatioAxisConstraint")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("AspectRatioAxisConstraint"), 0x7C);
}

if (auto it = ULocalPlayer::MemberOffsets.find(STR("CachedUniqueNetId")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("CachedUniqueNetId"), 0x48);
}

if (auto it = ULocalPlayer::MemberOffsets.find(STR("ControllerId")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("ControllerId"), 0x108);
}

if (auto it = ULocalPlayer::MemberOffsets.find(STR("LastViewLocation")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("LastViewLocation"), 0x70);
}

if (auto it = ULocalPlayer::MemberOffsets.find(STR("MonoViewState")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("MonoViewState"), 0xE0);
}

if (auto it = ULocalPlayer::MemberOffsets.find(STR("Origin")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("Origin"), 0x60);
}

if (auto it = ULocalPlayer::MemberOffsets.find(STR("Size")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("Size"), 0x68);
}

if (auto it = ULocalPlayer::MemberOffsets.find(STR("SlateOperations")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("SlateOperations"), 0x110);
}

if (auto it = ULocalPlayer::MemberOffsets.find(STR("StereoViewState")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("StereoViewState"), 0xB8);
}

if (auto it = ULocalPlayer::MemberOffsets.find(STR("ViewState")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("ViewState"), 0x90);
}

if (auto it = ULocalPlayer::MemberOffsets.find(STR("ViewportClient")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("ViewportClient"), 0x58);
}

if (auto it = ULocalPlayer::MemberOffsets.find(STR("bSentSplitJoin")); it == ULocalPlayer::MemberOffsets.end())
{
    ULocalPlayer::MemberOffsets.emplace(STR("bSentSplitJoin"), 0x88);
}

