std::unordered_map<File::StringType, int32_t> FByteProperty::MemberOffsets{};

UEnum*& FByteProperty::GetEnum()
{
    static auto offset = MemberOffsets.find(STR("Enum"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FByteProperty::Enum' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UEnum**>(this, offset->second);
}
const UEnum*& FByteProperty::GetEnum() const
{
    static auto offset = MemberOffsets.find(STR("Enum"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FByteProperty::Enum' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UEnum**>(this, offset->second);
}

