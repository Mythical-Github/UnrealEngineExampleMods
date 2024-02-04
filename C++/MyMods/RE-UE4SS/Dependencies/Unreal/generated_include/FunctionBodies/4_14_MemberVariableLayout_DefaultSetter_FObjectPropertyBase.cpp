if (auto it = FObjectPropertyBase::MemberOffsets.find(STR("PropertyClass")); it == FObjectPropertyBase::MemberOffsets.end())
{
    FObjectPropertyBase::MemberOffsets.emplace(STR("PropertyClass"), 0x78);
}

