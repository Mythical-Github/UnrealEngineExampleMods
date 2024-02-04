std::unordered_map<File::StringType, int32_t> FSetProperty::MemberOffsets{};

FProperty*& FSetProperty::GetElementProp()
{
    static auto offset = MemberOffsets.find(STR("ElementProp"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FSetProperty::ElementProp' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& FSetProperty::GetElementProp() const
{
    static auto offset = MemberOffsets.find(STR("ElementProp"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FSetProperty::ElementProp' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

