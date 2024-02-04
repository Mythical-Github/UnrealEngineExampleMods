std::unordered_map<File::StringType, int32_t> FDelegateProperty::MemberOffsets{};

UFunction*& FDelegateProperty::GetSignatureFunction()
{
    static auto offset = MemberOffsets.find(STR("SignatureFunction"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FDelegateProperty::SignatureFunction' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UFunction**>(this, offset->second);
}
const UFunction*& FDelegateProperty::GetSignatureFunction() const
{
    static auto offset = MemberOffsets.find(STR("SignatureFunction"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FDelegateProperty::SignatureFunction' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UFunction**>(this, offset->second);
}

