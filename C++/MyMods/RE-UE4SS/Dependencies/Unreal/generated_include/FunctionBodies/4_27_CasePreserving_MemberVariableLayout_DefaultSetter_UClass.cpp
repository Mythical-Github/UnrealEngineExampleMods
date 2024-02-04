if (auto it = UClass::MemberOffsets.find(STR("ClassAddReferencedObjects")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("ClassAddReferencedObjects"), 0xC8);
}

if (auto it = UClass::MemberOffsets.find(STR("ClassConfigName")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("ClassConfigName"), 0xF0);
}

if (auto it = UClass::MemberOffsets.find(STR("ClassConstructor")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("ClassConstructor"), 0xB8);
}

if (auto it = UClass::MemberOffsets.find(STR("ClassDefaultObject")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("ClassDefaultObject"), 0x128);
}

if (auto it = UClass::MemberOffsets.find(STR("ClassFlags")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("ClassFlags"), 0xD4);
}

if (auto it = UClass::MemberOffsets.find(STR("ClassGeneratedBy")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("ClassGeneratedBy"), 0xE8);
}

if (auto it = UClass::MemberOffsets.find(STR("ClassUnique")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("ClassUnique"), 0xD0);
}

if (auto it = UClass::MemberOffsets.find(STR("ClassVTableHelperCtorCaller")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("ClassVTableHelperCtorCaller"), 0xC0);
}

if (auto it = UClass::MemberOffsets.find(STR("ClassWithin")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("ClassWithin"), 0xE0);
}

if (auto it = UClass::MemberOffsets.find(STR("FirstOwnedClassRep")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("FirstOwnedClassRep"), 0x120);
}

if (auto it = UClass::MemberOffsets.find(STR("Interfaces")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("Interfaces"), 0x1E8);
}

if (auto it = UClass::MemberOffsets.find(STR("NetFields")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("NetFields"), 0x110);
}

if (auto it = UClass::MemberOffsets.find(STR("SparseClassData")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("SparseClassData"), 0x130);
}

if (auto it = UClass::MemberOffsets.find(STR("SparseClassDataStruct")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("SparseClassDataStruct"), 0x138);
}

if (auto it = UClass::MemberOffsets.find(STR("bCooked")); it == UClass::MemberOffsets.end())
{
    UClass::MemberOffsets.emplace(STR("bCooked"), 0xD0);
}

