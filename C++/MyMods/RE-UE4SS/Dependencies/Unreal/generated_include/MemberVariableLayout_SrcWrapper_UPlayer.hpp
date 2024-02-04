std::unordered_map<File::StringType, int32_t> UPlayer::MemberOffsets{};

int32& UPlayer::GetConfiguredInternetSpeed()
{
    static auto offset = MemberOffsets.find(STR("ConfiguredInternetSpeed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UPlayer::ConfiguredInternetSpeed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UPlayer::GetConfiguredInternetSpeed() const
{
    static auto offset = MemberOffsets.find(STR("ConfiguredInternetSpeed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UPlayer::ConfiguredInternetSpeed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

int32& UPlayer::GetConfiguredLanSpeed()
{
    static auto offset = MemberOffsets.find(STR("ConfiguredLanSpeed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UPlayer::ConfiguredLanSpeed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UPlayer::GetConfiguredLanSpeed() const
{
    static auto offset = MemberOffsets.find(STR("ConfiguredLanSpeed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UPlayer::ConfiguredLanSpeed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

int32& UPlayer::GetCurrentNetSpeed()
{
    static auto offset = MemberOffsets.find(STR("CurrentNetSpeed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UPlayer::CurrentNetSpeed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UPlayer::GetCurrentNetSpeed() const
{
    static auto offset = MemberOffsets.find(STR("CurrentNetSpeed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UPlayer::CurrentNetSpeed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

