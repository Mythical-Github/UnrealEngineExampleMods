if (auto it = FFieldPathProperty::MemberOffsets.find(STR("PropertyClass")); it == FFieldPathProperty::MemberOffsets.end())
{
    FFieldPathProperty::MemberOffsets.emplace(STR("PropertyClass"), 0x78);
}

