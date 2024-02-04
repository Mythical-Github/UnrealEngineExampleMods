std::unordered_map<File::StringType, int32_t> UField::MemberOffsets{};

UField*& UField::GetNext()
{
    static auto offset = MemberOffsets.find(STR("Next"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UField::Next' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UField**>(this, offset->second);
}
const UField*& UField::GetNext() const
{
    static auto offset = MemberOffsets.find(STR("Next"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UField::Next' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UField**>(this, offset->second);
}

