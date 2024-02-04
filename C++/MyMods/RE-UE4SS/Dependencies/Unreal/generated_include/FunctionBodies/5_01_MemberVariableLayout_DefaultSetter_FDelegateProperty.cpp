if (auto it = FDelegateProperty::MemberOffsets.find(STR("SignatureFunction")); it == FDelegateProperty::MemberOffsets.end())
{
    FDelegateProperty::MemberOffsets.emplace(STR("SignatureFunction"), 0x78);
}

