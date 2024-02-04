if (auto it = FSetProperty::MemberOffsets.find(STR("ElementProp")); it == FSetProperty::MemberOffsets.end())
{
    FSetProperty::MemberOffsets.emplace(STR("ElementProp"), 0x80);
}

