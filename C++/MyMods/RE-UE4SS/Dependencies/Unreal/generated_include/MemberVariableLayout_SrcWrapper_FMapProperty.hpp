std::unordered_map<File::StringType, int32_t> FMapProperty::MemberOffsets{};

FProperty*& FMapProperty::GetKeyProp()
{
    static auto offset = MemberOffsets.find(STR("KeyProp"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FMapProperty::KeyProp' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& FMapProperty::GetKeyProp() const
{
    static auto offset = MemberOffsets.find(STR("KeyProp"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FMapProperty::KeyProp' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

FProperty*& FMapProperty::GetValueProp()
{
    static auto offset = MemberOffsets.find(STR("ValueProp"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FMapProperty::ValueProp' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& FMapProperty::GetValueProp() const
{
    static auto offset = MemberOffsets.find(STR("ValueProp"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FMapProperty::ValueProp' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

