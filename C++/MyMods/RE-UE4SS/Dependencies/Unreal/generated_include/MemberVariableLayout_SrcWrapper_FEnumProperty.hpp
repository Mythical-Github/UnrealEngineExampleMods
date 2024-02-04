std::unordered_map<File::StringType, int32_t> FEnumProperty::MemberOffsets{};

UEnum*& FEnumProperty::GetEnum()
{
    static auto offset = MemberOffsets.find(STR("Enum"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FEnumProperty::Enum' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UEnum**>(this, offset->second);
}
const UEnum*& FEnumProperty::GetEnum() const
{
    static auto offset = MemberOffsets.find(STR("Enum"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FEnumProperty::Enum' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UEnum**>(this, offset->second);
}

FNumericProperty*& FEnumProperty::GetUnderlyingProp()
{
    static auto offset = MemberOffsets.find(STR("UnderlyingProp"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FEnumProperty::UnderlyingProp' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FNumericProperty**>(this, offset->second);
}
const FNumericProperty*& FEnumProperty::GetUnderlyingProp() const
{
    static auto offset = MemberOffsets.find(STR("UnderlyingProp"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FEnumProperty::UnderlyingProp' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FNumericProperty**>(this, offset->second);
}

