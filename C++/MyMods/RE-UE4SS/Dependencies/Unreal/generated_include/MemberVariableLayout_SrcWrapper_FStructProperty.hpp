std::unordered_map<File::StringType, int32_t> FStructProperty::MemberOffsets{};

UScriptStruct*& FStructProperty::GetStruct()
{
    static auto offset = MemberOffsets.find(STR("Struct"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FStructProperty::Struct' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UScriptStruct**>(this, offset->second);
}
const UScriptStruct*& FStructProperty::GetStruct() const
{
    static auto offset = MemberOffsets.find(STR("Struct"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FStructProperty::Struct' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UScriptStruct**>(this, offset->second);
}

