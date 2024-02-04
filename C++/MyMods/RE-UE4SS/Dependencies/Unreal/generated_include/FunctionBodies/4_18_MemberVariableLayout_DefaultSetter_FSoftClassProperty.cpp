if (auto it = FSoftClassProperty::MemberOffsets.find(STR("MetaClass")); it == FSoftClassProperty::MemberOffsets.end())
{
    FSoftClassProperty::MemberOffsets.emplace(STR("MetaClass"), 0x78);
}

