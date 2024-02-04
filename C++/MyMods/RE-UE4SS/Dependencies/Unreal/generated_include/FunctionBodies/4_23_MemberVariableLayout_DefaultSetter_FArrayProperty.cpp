if (auto it = FArrayProperty::MemberOffsets.find(STR("Inner")); it == FArrayProperty::MemberOffsets.end())
{
    FArrayProperty::MemberOffsets.emplace(STR("Inner"), 0x70);
}

