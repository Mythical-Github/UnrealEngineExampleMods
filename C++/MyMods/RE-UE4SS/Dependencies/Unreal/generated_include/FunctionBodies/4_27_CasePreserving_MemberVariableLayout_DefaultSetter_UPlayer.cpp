if (auto it = UPlayer::MemberOffsets.find(STR("ConfiguredInternetSpeed")); it == UPlayer::MemberOffsets.end())
{
    UPlayer::MemberOffsets.emplace(STR("ConfiguredInternetSpeed"), 0x44);
}

if (auto it = UPlayer::MemberOffsets.find(STR("ConfiguredLanSpeed")); it == UPlayer::MemberOffsets.end())
{
    UPlayer::MemberOffsets.emplace(STR("ConfiguredLanSpeed"), 0x48);
}

if (auto it = UPlayer::MemberOffsets.find(STR("CurrentNetSpeed")); it == UPlayer::MemberOffsets.end())
{
    UPlayer::MemberOffsets.emplace(STR("CurrentNetSpeed"), 0x40);
}

