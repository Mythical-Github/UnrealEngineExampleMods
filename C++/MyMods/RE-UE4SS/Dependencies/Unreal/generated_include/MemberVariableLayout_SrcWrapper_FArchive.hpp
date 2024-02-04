std::unordered_map<File::StringType, int32_t> FArchive::MemberOffsets{};

uint8& FArchive::GetArAllowLazyLoading()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArAllowLazyLoading"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArAllowLazyLoading' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArAllowLazyLoading() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArAllowLazyLoading"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArAllowLazyLoading' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArContainsCode()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArContainsCode"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArContainsCode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArContainsCode() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArContainsCode"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArContainsCode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArContainsMap()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArContainsMap"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArContainsMap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArContainsMap() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArContainsMap"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArContainsMap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

FCustomPropertyListNode*& FArchive::GetArCustomPropertyList()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArCustomPropertyList"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArCustomPropertyList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FCustomPropertyListNode**>(this, offset->second);
}
const FCustomPropertyListNode*& FArchive::GetArCustomPropertyList() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArCustomPropertyList"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArCustomPropertyList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FCustomPropertyListNode**>(this, offset->second);
}

uint32& FArchive::GetArEngineNetVer()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArEngineNetVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArEngineNetVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& FArchive::GetArEngineNetVer() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArEngineNetVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArEngineNetVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

FEngineVersionBase& FArchive::GetArEngineVer()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArEngineVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArEngineVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FEngineVersionBase*>(this, offset->second);
}
const FEngineVersionBase& FArchive::GetArEngineVer() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArEngineVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArEngineVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FEngineVersionBase*>(this, offset->second);
}

uint8& FArchive::GetArForceByteSwapping()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArForceByteSwapping"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArForceByteSwapping' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArForceByteSwapping() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArForceByteSwapping"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArForceByteSwapping' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArForceUnicode()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArForceUnicode"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArForceUnicode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArForceUnicode() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArForceUnicode"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArForceUnicode' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint32& FArchive::GetArGameNetVer()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArGameNetVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArGameNetVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& FArchive::GetArGameNetVer() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArGameNetVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArGameNetVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint8& FArchive::GetArIgnoreArchetypeRef()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreArchetypeRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIgnoreArchetypeRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIgnoreArchetypeRef() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreArchetypeRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIgnoreArchetypeRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIgnoreClassGeneratedByRef()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreClassGeneratedByRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIgnoreClassGeneratedByRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIgnoreClassGeneratedByRef() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreClassGeneratedByRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIgnoreClassGeneratedByRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIgnoreClassRef()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreClassRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIgnoreClassRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIgnoreClassRef() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreClassRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIgnoreClassRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIgnoreOuterRef()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreOuterRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIgnoreOuterRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIgnoreOuterRef() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIgnoreOuterRef"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIgnoreOuterRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsCountingMemory()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsCountingMemory"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsCountingMemory' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsCountingMemory() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsCountingMemory"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsCountingMemory' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsCriticalError()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsCriticalError"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsCriticalError' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsCriticalError() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsCriticalError"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsCriticalError' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsError()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsError"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsError' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsError() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsError"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsError' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsFilterEditorOnly()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsFilterEditorOnly"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsFilterEditorOnly' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsFilterEditorOnly() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsFilterEditorOnly"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsFilterEditorOnly' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsLoading()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsLoading"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsLoading' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsLoading() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsLoading"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsLoading' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsModifyingWeakAndStrongReferences()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsModifyingWeakAndStrongReferences"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsModifyingWeakAndStrongReferences' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsModifyingWeakAndStrongReferences() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsModifyingWeakAndStrongReferences"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsModifyingWeakAndStrongReferences' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsNetArchive()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsNetArchive"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsNetArchive' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsNetArchive() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsNetArchive"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsNetArchive' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsObjectReferenceCollector()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsObjectReferenceCollector"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsObjectReferenceCollector' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsObjectReferenceCollector() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsObjectReferenceCollector"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsObjectReferenceCollector' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsPersistent()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsPersistent"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsPersistent' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsPersistent() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsPersistent"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsPersistent' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsSaveGame()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsSaveGame"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsSaveGame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsSaveGame() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsSaveGame"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsSaveGame' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsSaving()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsSaving"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsSaving' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsSaving() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsSaving"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsSaving' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsTextFormat()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsTextFormat"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsTextFormat' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsTextFormat() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsTextFormat"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsTextFormat' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArIsTransacting()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsTransacting"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsTransacting' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArIsTransacting() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArIsTransacting"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArIsTransacting' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

int32& FArchive::GetArLicenseeUE4Ver()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArLicenseeUE4Ver"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArLicenseeUE4Ver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& FArchive::GetArLicenseeUE4Ver() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArLicenseeUE4Ver"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArLicenseeUE4Ver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

int64& FArchive::GetArMaxSerializeSize()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArMaxSerializeSize"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArMaxSerializeSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int64*>(this, offset->second);
}
const int64& FArchive::GetArMaxSerializeSize() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArMaxSerializeSize"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArMaxSerializeSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int64*>(this, offset->second);
}

int32& FArchive::GetArNetVer()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArNetVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArNetVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& FArchive::GetArNetVer() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArNetVer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArNetVer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

uint8& FArchive::GetArNoDelta()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArNoDelta"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArNoDelta' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArNoDelta() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArNoDelta"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArNoDelta' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArNoIntraPropertyDelta()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArNoIntraPropertyDelta"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArNoIntraPropertyDelta' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArNoIntraPropertyDelta() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArNoIntraPropertyDelta"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArNoIntraPropertyDelta' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint32& FArchive::GetArPortFlags()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArPortFlags"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArPortFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& FArchive::GetArPortFlags() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArPortFlags"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArPortFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint8& FArchive::GetArRequiresLocalizationGather()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArRequiresLocalizationGather"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArRequiresLocalizationGather' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArRequiresLocalizationGather() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArRequiresLocalizationGather"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArRequiresLocalizationGather' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

int32& FArchive::GetArSerializingDefaults()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArSerializingDefaults"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArSerializingDefaults' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& FArchive::GetArSerializingDefaults() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArSerializingDefaults"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArSerializingDefaults' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

uint8& FArchive::GetArShouldSkipBulkData()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArShouldSkipBulkData"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArShouldSkipBulkData' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArShouldSkipBulkData() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArShouldSkipBulkData"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArShouldSkipBulkData' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

int32& FArchive::GetArUE4Ver()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUE4Ver"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArUE4Ver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& FArchive::GetArUE4Ver() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUE4Ver"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArUE4Ver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

uint8& FArchive::GetArUseCustomPropertyList()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUseCustomPropertyList"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArUseCustomPropertyList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArUseCustomPropertyList() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArUseCustomPropertyList"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArUseCustomPropertyList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FArchive::GetArWantBinaryPropertySerialization()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArWantBinaryPropertySerialization"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArWantBinaryPropertySerialization' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FArchive::GetArWantBinaryPropertySerialization() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("ArWantBinaryPropertySerialization"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::ArWantBinaryPropertySerialization' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

ITargetPlatform*& FArchive::GetCookingTargetPlatform()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("CookingTargetPlatform"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::CookingTargetPlatform' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<ITargetPlatform**>(this, offset->second);
}
const ITargetPlatform*& FArchive::GetCookingTargetPlatform() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("CookingTargetPlatform"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::CookingTargetPlatform' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const ITargetPlatform**>(this, offset->second);
}

FCustomVersionContainer*& FArchive::GetCustomVersionContainer()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("CustomVersionContainer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::CustomVersionContainer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FCustomVersionContainer**>(this, offset->second);
}
const FCustomVersionContainer*& FArchive::GetCustomVersionContainer() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("CustomVersionContainer"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::CustomVersionContainer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FCustomVersionContainer**>(this, offset->second);
}

FProperty*& FArchive::GetSerializedProperty()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("SerializedProperty"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::SerializedProperty' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& FArchive::GetSerializedProperty() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("SerializedProperty"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::SerializedProperty' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

bool& FArchive::GetbCustomVersionsAreReset()
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("bCustomVersionsAreReset"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::bCustomVersionsAreReset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& FArchive::GetbCustomVersionsAreReset() const
{
    static auto& offsets = Version::IsBelow(4, 25) ? FArchive::MemberOffsets : FArchiveState::MemberOffsets;
    static auto offset = offsets.find(STR("bCustomVersionsAreReset"));
    if (offset == offsets.end()) { throw std::runtime_error{"Tried getting member variable 'FArchive::bCustomVersionsAreReset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

