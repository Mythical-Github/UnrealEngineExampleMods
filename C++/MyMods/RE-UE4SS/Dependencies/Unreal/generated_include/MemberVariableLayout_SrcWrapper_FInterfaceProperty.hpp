std::unordered_map<File::StringType, int32_t> FInterfaceProperty::MemberOffsets{};

UClass*& FInterfaceProperty::GetInterfaceClass()
{
    static auto offset = MemberOffsets.find(STR("InterfaceClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FInterfaceProperty::InterfaceClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UClass**>(this, offset->second);
}
const UClass*& FInterfaceProperty::GetInterfaceClass() const
{
    static auto offset = MemberOffsets.find(STR("InterfaceClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FInterfaceProperty::InterfaceClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UClass**>(this, offset->second);
}

