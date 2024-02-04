if (auto it = FClassProperty::MemberOffsets.find(STR("MetaClass")); it == FClassProperty::MemberOffsets.end())
{
    FClassProperty::MemberOffsets.emplace(STR("MetaClass"), 0x88);
}

