if (auto it = FStructProperty::MemberOffsets.find(STR("Struct")); it == FStructProperty::MemberOffsets.end())
{
    FStructProperty::MemberOffsets.emplace(STR("Struct"), 0x70);
}

