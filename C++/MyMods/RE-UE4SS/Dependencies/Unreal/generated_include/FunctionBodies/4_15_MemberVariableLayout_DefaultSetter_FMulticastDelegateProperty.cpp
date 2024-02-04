if (auto it = FMulticastDelegateProperty::MemberOffsets.find(STR("SignatureFunction")); it == FMulticastDelegateProperty::MemberOffsets.end())
{
    FMulticastDelegateProperty::MemberOffsets.emplace(STR("SignatureFunction"), 0x78);
}

