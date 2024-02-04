if (auto it = UField::MemberOffsets.find(STR("Next")); it == UField::MemberOffsets.end())
{
    UField::MemberOffsets.emplace(STR("Next"), 0x28);
}

