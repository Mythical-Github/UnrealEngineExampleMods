std::unordered_map<File::StringType, int32_t> FArchiveState::MemberOffsets{};

uint8& FArchiveState::GetArAllowLazyLoading()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArAllowLazyLoading"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArAllowLazyLoading' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArAllowLazyLoading() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArAllowLazyLoading"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArAllowLazyLoading' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArContainsCode()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArContainsCode"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArContainsCode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArContainsCode() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArContainsCode"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArContainsCode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArContainsMap()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArContainsMap"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArContainsMap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArContainsMap() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArContainsMap"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArContainsMap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

FCustomPropertyListNode*& FArchiveState::GetArCustomPropertyList()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArCustomPropertyList"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArCustomPropertyList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FCustomPropertyListNode**>(this, offset->second);
}
const FCustomPropertyListNode*& FArchiveState::GetArCustomPropertyList() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArCustomPropertyList"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArCustomPropertyList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FCustomPropertyListNode**>(this, offset->second);
}

uint32& FArchiveState::GetArEngineNetVer()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArEngineNetVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArEngineNetVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& FArchiveState::GetArEngineNetVer() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArEngineNetVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArEngineNetVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

FEngineVersionBase& FArchiveState::GetArEngineVer()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArEngineVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArEngineVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FEngineVersionBase*>(this, offset->second);
}
const FEngineVersionBase& FArchiveState::GetArEngineVer() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArEngineVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArEngineVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FEngineVersionBase*>(this, offset->second);
}

uint8& FArchiveState::GetArForceByteSwapping()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArForceByteSwapping"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArForceByteSwapping' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArForceByteSwapping() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArForceByteSwapping"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArForceByteSwapping' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArForceUnicode()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArForceUnicode"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArForceUnicode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArForceUnicode() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArForceUnicode"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArForceUnicode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint32& FArchiveState::GetArGameNetVer()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArGameNetVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArGameNetVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& FArchiveState::GetArGameNetVer() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArGameNetVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArGameNetVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint8& FArchiveState::GetArIgnoreArchetypeRef()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreArchetypeRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIgnoreArchetypeRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIgnoreArchetypeRef() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreArchetypeRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIgnoreArchetypeRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIgnoreClassGeneratedByRef()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreClassGeneratedByRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIgnoreClassGeneratedByRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIgnoreClassGeneratedByRef() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreClassGeneratedByRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIgnoreClassGeneratedByRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIgnoreClassRef()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreClassRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIgnoreClassRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIgnoreClassRef() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreClassRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIgnoreClassRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIgnoreOuterRef()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreOuterRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIgnoreOuterRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIgnoreOuterRef() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreOuterRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIgnoreOuterRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsCountingMemory()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsCountingMemory"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsCountingMemory' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsCountingMemory() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsCountingMemory"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsCountingMemory' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsCriticalError()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsCriticalError"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsCriticalError' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsCriticalError() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsCriticalError"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsCriticalError' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsError()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsError"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsError' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsError() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsError"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsError' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsFilterEditorOnly()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsFilterEditorOnly"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsFilterEditorOnly' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsFilterEditorOnly() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsFilterEditorOnly"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsFilterEditorOnly' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsLoading()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsLoading"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsLoading' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsLoading() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsLoading"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsLoading' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsLoadingFromCookedPackage()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsLoadingFromCookedPackage"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsLoadingFromCookedPackage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsLoadingFromCookedPackage() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsLoadingFromCookedPackage"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsLoadingFromCookedPackage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsModifyingWeakAndStrongReferences()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsModifyingWeakAndStrongReferences"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsModifyingWeakAndStrongReferences' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsModifyingWeakAndStrongReferences() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsModifyingWeakAndStrongReferences"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsModifyingWeakAndStrongReferences' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsNetArchive()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsNetArchive"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsNetArchive' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsNetArchive() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsNetArchive"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsNetArchive' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsObjectReferenceCollector()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsObjectReferenceCollector"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsObjectReferenceCollector' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsObjectReferenceCollector() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsObjectReferenceCollector"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsObjectReferenceCollector' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsPersistent()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsPersistent"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsPersistent' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsPersistent() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsPersistent"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsPersistent' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsSaveGame()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsSaveGame"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsSaveGame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsSaveGame() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsSaveGame"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsSaveGame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsSaving()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsSaving"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsSaving' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsSaving() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsSaving"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsSaving' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsTextFormat()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsTextFormat"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsTextFormat' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsTextFormat() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsTextFormat"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsTextFormat' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArIsTransacting()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsTransacting"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsTransacting' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArIsTransacting() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsTransacting"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArIsTransacting' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

int32& FArchiveState::GetArLicenseeUE4Ver()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArLicenseeUE4Ver"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArLicenseeUE4Ver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& FArchiveState::GetArLicenseeUE4Ver() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArLicenseeUE4Ver"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArLicenseeUE4Ver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

int32& FArchiveState::GetArLicenseeUEVer()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArLicenseeUEVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArLicenseeUEVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& FArchiveState::GetArLicenseeUEVer() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArLicenseeUEVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArLicenseeUEVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

int64& FArchiveState::GetArMaxSerializeSize()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArMaxSerializeSize"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArMaxSerializeSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int64*>(this, offset->second);
}
const int64& FArchiveState::GetArMaxSerializeSize() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArMaxSerializeSize"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArMaxSerializeSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int64*>(this, offset->second);
}

uint8& FArchiveState::GetArNoDelta()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArNoDelta"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArNoDelta' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArNoDelta() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArNoDelta"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArNoDelta' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArNoIntraPropertyDelta()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArNoIntraPropertyDelta"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArNoIntraPropertyDelta' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArNoIntraPropertyDelta() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArNoIntraPropertyDelta"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArNoIntraPropertyDelta' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint32& FArchiveState::GetArPortFlags()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArPortFlags"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArPortFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& FArchiveState::GetArPortFlags() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArPortFlags"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArPortFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint8& FArchiveState::GetArRequiresLocalizationGather()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArRequiresLocalizationGather"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArRequiresLocalizationGather' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArRequiresLocalizationGather() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArRequiresLocalizationGather"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArRequiresLocalizationGather' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

int32& FArchiveState::GetArSerializingDefaults()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArSerializingDefaults"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArSerializingDefaults' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& FArchiveState::GetArSerializingDefaults() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArSerializingDefaults"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArSerializingDefaults' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

uint8& FArchiveState::GetArShouldSkipBulkData()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArShouldSkipBulkData"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArShouldSkipBulkData' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArShouldSkipBulkData() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArShouldSkipBulkData"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArShouldSkipBulkData' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArShouldSkipCompilingAssets()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArShouldSkipCompilingAssets"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArShouldSkipCompilingAssets' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArShouldSkipCompilingAssets() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArShouldSkipCompilingAssets"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArShouldSkipCompilingAssets' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

int32& FArchiveState::GetArUE4Ver()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUE4Ver"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArUE4Ver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& FArchiveState::GetArUE4Ver() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUE4Ver"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArUE4Ver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

FPackageFileVersion& FArchiveState::GetArUEVer()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUEVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArUEVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FPackageFileVersion*>(this, offset->second);
}
const FPackageFileVersion& FArchiveState::GetArUEVer() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUEVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArUEVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FPackageFileVersion*>(this, offset->second);
}

uint8& FArchiveState::GetArUseCustomPropertyList()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUseCustomPropertyList"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArUseCustomPropertyList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArUseCustomPropertyList() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUseCustomPropertyList"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArUseCustomPropertyList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArUseUnversionedPropertySerialization()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUseUnversionedPropertySerialization"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArUseUnversionedPropertySerialization' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArUseUnversionedPropertySerialization() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUseUnversionedPropertySerialization"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArUseUnversionedPropertySerialization' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchiveState::GetArWantBinaryPropertySerialization()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArWantBinaryPropertySerialization"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArWantBinaryPropertySerialization' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchiveState::GetArWantBinaryPropertySerialization() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArWantBinaryPropertySerialization"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::ArWantBinaryPropertySerialization' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

ITargetPlatform*& FArchiveState::GetCookingTargetPlatform()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("CookingTargetPlatform"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::CookingTargetPlatform' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<ITargetPlatform**>(this, offset->second);
}
const ITargetPlatform*& FArchiveState::GetCookingTargetPlatform() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("CookingTargetPlatform"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::CookingTargetPlatform' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const ITargetPlatform**>(this, offset->second);
}

FCustomVersionContainer*& FArchiveState::GetCustomVersionContainer()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("CustomVersionContainer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::CustomVersionContainer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FCustomVersionContainer**>(this, offset->second);
}
const FCustomVersionContainer*& FArchiveState::GetCustomVersionContainer() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("CustomVersionContainer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::CustomVersionContainer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FCustomVersionContainer**>(this, offset->second);
}

FArchiveState*& FArchiveState::GetNextProxy()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("NextProxy"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::NextProxy' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FArchiveState**>(this, offset->second);
}
const FArchiveState*& FArchiveState::GetNextProxy() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("NextProxy"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::NextProxy' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FArchiveState**>(this, offset->second);
}

FProperty*& FArchiveState::GetSerializedProperty()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("SerializedProperty"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::SerializedProperty' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& FArchiveState::GetSerializedProperty() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("SerializedProperty"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::SerializedProperty' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

bool& FArchiveState::GetbCustomVersionsAreReset()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("bCustomVersionsAreReset"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::bCustomVersionsAreReset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& FArchiveState::GetbCustomVersionsAreReset() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("bCustomVersionsAreReset"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchiveState::bCustomVersionsAreReset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

