if (auto it = FMapProperty::MemberOffsets.find(STR("KeyProp")); it == FMapProperty::MemberOffsets.end())
{
    FMapProperty::MemberOffsets.emplace(STR("KeyProp"), 0x70);
}

if (auto it = FMapProperty::MemberOffsets.find(STR("ValueProp")); it == FMapProperty::MemberOffsets.end())
{
    FMapProperty::MemberOffsets.emplace(STR("ValueProp"), 0x78);
}

