if (auto it = UScriptStruct::ICppStructOps::MemberOffsets.find(STR("Alignment")); it == UScriptStruct::ICppStructOps::MemberOffsets.end())
{
    UScriptStruct::ICppStructOps::MemberOffsets.emplace(STR("Alignment"), 0xC);
}

if (auto it = UScriptStruct::ICppStructOps::MemberOffsets.find(STR("Size")); it == UScriptStruct::ICppStructOps::MemberOffsets.end())
{
    UScriptStruct::ICppStructOps::MemberOffsets.emplace(STR("Size"), 0x8);
}

