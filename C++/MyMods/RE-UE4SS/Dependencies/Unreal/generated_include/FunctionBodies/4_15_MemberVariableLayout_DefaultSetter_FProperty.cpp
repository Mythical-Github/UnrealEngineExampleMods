if (auto it = FProperty::MemberOffsets.find(STR("ArrayDim")); it == FProperty::MemberOffsets.end())
{
    FProperty::MemberOffsets.emplace(STR("ArrayDim"), 0x30);
}

if (auto it = FProperty::MemberOffsets.find(STR("DestructorLinkNext")); it == FProperty::MemberOffsets.end())
{
    FProperty::MemberOffsets.emplace(STR("DestructorLinkNext"), 0x68);
}

if (auto it = FProperty::MemberOffsets.find(STR("ElementSize")); it == FProperty::MemberOffsets.end())
{
    FProperty::MemberOffsets.emplace(STR("ElementSize"), 0x34);
}

if (auto it = FProperty::MemberOffsets.find(STR("NextRef")); it == FProperty::MemberOffsets.end())
{
    FProperty::MemberOffsets.emplace(STR("NextRef"), 0x60);
}

if (auto it = FProperty::MemberOffsets.find(STR("Offset_Internal")); it == FProperty::MemberOffsets.end())
{
    FProperty::MemberOffsets.emplace(STR("Offset_Internal"), 0x50);
}

if (auto it = FProperty::MemberOffsets.find(STR("PostConstructLinkNext")); it == FProperty::MemberOffsets.end())
{
    FProperty::MemberOffsets.emplace(STR("PostConstructLinkNext"), 0x70);
}

if (auto it = FProperty::MemberOffsets.find(STR("PropertyFlags")); it == FProperty::MemberOffsets.end())
{
    FProperty::MemberOffsets.emplace(STR("PropertyFlags"), 0x38);
}

if (auto it = FProperty::MemberOffsets.find(STR("PropertyLinkNext")); it == FProperty::MemberOffsets.end())
{
    FProperty::MemberOffsets.emplace(STR("PropertyLinkNext"), 0x58);
}

if (auto it = FProperty::MemberOffsets.find(STR("RepIndex")); it == FProperty::MemberOffsets.end())
{
    FProperty::MemberOffsets.emplace(STR("RepIndex"), 0x40);
}

if (auto it = FProperty::MemberOffsets.find(STR("RepNotifyFunc")); it == FProperty::MemberOffsets.end())
{
    FProperty::MemberOffsets.emplace(STR("RepNotifyFunc"), 0x48);
}

