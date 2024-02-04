std::unordered_map<File::StringType, int32_t> FFieldPathProperty::MemberOffsets{};

FFieldClass*& FFieldPathProperty::GetPropertyClass()
{
    static auto offset = MemberOffsets.find(STR("PropertyClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FFieldPathProperty::PropertyClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FFieldClass**>(this, offset->second);
}
const FFieldClass*& FFieldPathProperty::GetPropertyClass() const
{
    static auto offset = MemberOffsets.find(STR("PropertyClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FFieldPathProperty::PropertyClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FFieldClass**>(this, offset->second);
}

