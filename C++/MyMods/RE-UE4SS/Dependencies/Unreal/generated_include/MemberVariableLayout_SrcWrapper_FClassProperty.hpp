std::unordered_map<File::StringType, int32_t> FClassProperty::MemberOffsets{};

UClass*& FClassProperty::GetMetaClass()
{
    static auto offset = MemberOffsets.find(STR("MetaClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FClassProperty::MetaClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UClass**>(this, offset->second);
}
const UClass*& FClassProperty::GetMetaClass() const
{
    static auto offset = MemberOffsets.find(STR("MetaClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FClassProperty::MetaClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UClass**>(this, offset->second);
}

