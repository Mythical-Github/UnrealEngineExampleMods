if (auto it = FField::MemberOffsets.find(STR("ClassPrivate")); it == FField::MemberOffsets.end())
{
    FField::MemberOffsets.emplace(STR("ClassPrivate"), 0x8);
}

if (auto it = FField::MemberOffsets.find(STR("FlagsPrivate")); it == FField::MemberOffsets.end())
{
    FField::MemberOffsets.emplace(STR("FlagsPrivate"), 0x34);
}

if (auto it = FField::MemberOffsets.find(STR("NamePrivate")); it == FField::MemberOffsets.end())
{
    FField::MemberOffsets.emplace(STR("NamePrivate"), 0x28);
}

if (auto it = FField::MemberOffsets.find(STR("Next")); it == FField::MemberOffsets.end())
{
    FField::MemberOffsets.emplace(STR("Next"), 0x20);
}

if (auto it = FField::MemberOffsets.find(STR("Owner")); it == FField::MemberOffsets.end())
{
    FField::MemberOffsets.emplace(STR("Owner"), 0x10);
}

