if (auto it = FEnumProperty::MemberOffsets.find(STR("Enum")); it == FEnumProperty::MemberOffsets.end())
{
    FEnumProperty::MemberOffsets.emplace(STR("Enum"), 0x78);
}

if (auto it = FEnumProperty::MemberOffsets.find(STR("UnderlyingProp")); it == FEnumProperty::MemberOffsets.end())
{
    FEnumProperty::MemberOffsets.emplace(STR("UnderlyingProp"), 0x70);
}

