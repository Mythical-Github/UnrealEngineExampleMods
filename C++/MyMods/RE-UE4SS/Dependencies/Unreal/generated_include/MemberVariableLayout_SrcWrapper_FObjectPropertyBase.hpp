std::unordered_map<File::StringType, int32_t> FObjectPropertyBase::MemberOffsets{};

UClass*& FObjectPropertyBase::GetPropertyClass()
{
    static auto offset = MemberOffsets.find(STR("PropertyClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FObjectPropertyBase::PropertyClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UClass**>(this, offset->second);
}
const UClass*& FObjectPropertyBase::GetPropertyClass() const
{
    static auto offset = MemberOffsets.find(STR("PropertyClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FObjectPropertyBase::PropertyClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UClass**>(this, offset->second);
}

