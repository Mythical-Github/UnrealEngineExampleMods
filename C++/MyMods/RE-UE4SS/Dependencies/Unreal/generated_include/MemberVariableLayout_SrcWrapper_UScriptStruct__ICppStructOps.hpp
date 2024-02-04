std::unordered_map<File::StringType, int32_t> UScriptStruct::ICppStructOps::MemberOffsets{};

int32& UScriptStruct::ICppStructOps::GetAlignment()
{
    static auto offset = MemberOffsets.find(STR("Alignment"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::ICppStructOps::Alignment' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UScriptStruct::ICppStructOps::GetAlignment() const
{
    static auto offset = MemberOffsets.find(STR("Alignment"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::ICppStructOps::Alignment' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

int32& UScriptStruct::ICppStructOps::GetSize()
{
    static auto offset = MemberOffsets.find(STR("Size"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::ICppStructOps::Size' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UScriptStruct::ICppStructOps::GetSize() const
{
    static auto offset = MemberOffsets.find(STR("Size"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::ICppStructOps::Size' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

