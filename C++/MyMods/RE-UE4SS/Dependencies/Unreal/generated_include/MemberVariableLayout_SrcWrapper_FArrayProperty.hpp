std::unordered_map<File::StringType, int32_t> FArrayProperty::MemberOffsets{};

FProperty*& FArrayProperty::GetInner()
{
    static auto offset = MemberOffsets.find(STR("Inner"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArrayProperty::Inner' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& FArrayProperty::GetInner() const
{
    static auto offset = MemberOffsets.find(STR("Inner"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArrayProperty::Inner' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

