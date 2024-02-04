if (auto it = FByteProperty::MemberOffsets.find(STR("Enum")); it == FByteProperty::MemberOffsets.end())
{
    FByteProperty::MemberOffsets.emplace(STR("Enum"), 0x80);
}

