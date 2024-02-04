if (auto it = UObjectBase::MemberOffsets.find(STR("Class")); it == UObjectBase::MemberOffsets.end())
{
    UObjectBase::MemberOffsets.emplace(STR("Class"), 0x10);
}

if (auto it = UObjectBase::MemberOffsets.find(STR("InternalIndex")); it == UObjectBase::MemberOffsets.end())
{
    UObjectBase::MemberOffsets.emplace(STR("InternalIndex"), 0xC);
}

if (auto it = UObjectBase::MemberOffsets.find(STR("Name")); it == UObjectBase::MemberOffsets.end())
{
    UObjectBase::MemberOffsets.emplace(STR("Name"), 0x18);
}

if (auto it = UObjectBase::MemberOffsets.find(STR("ObjectFlags")); it == UObjectBase::MemberOffsets.end())
{
    UObjectBase::MemberOffsets.emplace(STR("ObjectFlags"), 0x8);
}

if (auto it = UObjectBase::MemberOffsets.find(STR("Outer")); it == UObjectBase::MemberOffsets.end())
{
    UObjectBase::MemberOffsets.emplace(STR("Outer"), 0x20);
}

