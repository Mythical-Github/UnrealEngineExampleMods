std::unordered_map<File::StringType, int32_t> FMulticastDelegateProperty::MemberOffsets{};

UFunction*& FMulticastDelegateProperty::GetSignatureFunction()
{
    static auto offset = MemberOffsets.find(STR("SignatureFunction"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FMulticastDelegateProperty::SignatureFunction' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UFunction**>(this, offset->second);
}
const UFunction*& FMulticastDelegateProperty::GetSignatureFunction() const
{
    static auto offset = MemberOffsets.find(STR("SignatureFunction"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FMulticastDelegateProperty::SignatureFunction' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UFunction**>(this, offset->second);
}

