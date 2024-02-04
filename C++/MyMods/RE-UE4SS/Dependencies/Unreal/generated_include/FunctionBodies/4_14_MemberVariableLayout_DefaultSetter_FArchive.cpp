if (auto it = FArchive::MemberOffsets.find(STR("ArAllowLazyLoading")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArAllowLazyLoading"), 0xA);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArContainsCode")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArContainsCode"), 0x9);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArContainsMap")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArContainsMap"), 0x9);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArCustomPropertyList")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArCustomPropertyList"), 0x48);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArEngineNetVer")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArEngineNetVer"), 0x34);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArEngineVer")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArEngineVer"), 0x28);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArForceByteSwapping")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArForceByteSwapping"), 0x9);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArForceUnicode")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArForceUnicode"), 0x8);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArGameNetVer")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArGameNetVer"), 0x38);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIgnoreArchetypeRef")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIgnoreArchetypeRef"), 0x9);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIgnoreClassGeneratedByRef")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIgnoreClassGeneratedByRef"), 0x9);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIgnoreClassRef")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIgnoreClassRef"), 0xA);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIgnoreOuterRef")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIgnoreOuterRef"), 0x9);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIsCountingMemory")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIsCountingMemory"), 0xA);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIsCriticalError")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIsCriticalError"), 0x8);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIsError")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIsError"), 0x8);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIsFilterEditorOnly")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIsFilterEditorOnly"), 0xA);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIsLoading")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIsLoading"), 0x8);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIsModifyingWeakAndStrongReferences")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIsModifyingWeakAndStrongReferences"), 0xA);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIsObjectReferenceCollector")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIsObjectReferenceCollector"), 0xA);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIsPersistent")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIsPersistent"), 0x8);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIsSaveGame")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIsSaveGame"), 0xA);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIsSaving")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIsSaving"), 0x8);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArIsTransacting")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArIsTransacting"), 0x8);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArLicenseeUE4Ver")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArLicenseeUE4Ver"), 0x24);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArMaxSerializeSize")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArMaxSerializeSize"), 0x18);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArNoDelta")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArNoDelta"), 0x9);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArPortFlags")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArPortFlags"), 0x10);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArRequiresLocalizationGather")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArRequiresLocalizationGather"), 0x9);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArSerializingDefaults")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArSerializingDefaults"), 0xC);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArShouldSkipBulkData")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArShouldSkipBulkData"), 0xA);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArUE4Ver")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArUE4Ver"), 0x20);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArUseCustomPropertyList")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArUseCustomPropertyList"), 0xB);
}

if (auto it = FArchive::MemberOffsets.find(STR("ArWantBinaryPropertySerialization")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("ArWantBinaryPropertySerialization"), 0x8);
}

if (auto it = FArchive::MemberOffsets.find(STR("CookingTargetPlatform")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("CookingTargetPlatform"), 0x50);
}

if (auto it = FArchive::MemberOffsets.find(STR("CustomVersionContainer")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("CustomVersionContainer"), 0x40);
}

if (auto it = FArchive::MemberOffsets.find(STR("SerializedProperty")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("SerializedProperty"), 0x58);
}

if (auto it = FArchive::MemberOffsets.find(STR("bCustomVersionsAreReset")); it == FArchive::MemberOffsets.end())
{
    FArchive::MemberOffsets.emplace(STR("bCustomVersionsAreReset"), 0x60);
}

