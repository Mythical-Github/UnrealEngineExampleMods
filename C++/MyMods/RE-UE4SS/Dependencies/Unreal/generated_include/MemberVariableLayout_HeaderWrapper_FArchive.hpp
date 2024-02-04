static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    uint8& GetArAllowLazyLoading();
    const uint8& GetArAllowLazyLoading() const;

public:
    uint8& GetArContainsCode();
    const uint8& GetArContainsCode() const;

public:
    uint8& GetArContainsMap();
    const uint8& GetArContainsMap() const;

public:
    FCustomPropertyListNode*& GetArCustomPropertyList();
    const FCustomPropertyListNode*& GetArCustomPropertyList() const;

public:
    uint32& GetArEngineNetVer();
    const uint32& GetArEngineNetVer() const;

public:
    FEngineVersionBase& GetArEngineVer();
    const FEngineVersionBase& GetArEngineVer() const;

public:
    uint8& GetArForceByteSwapping();
    const uint8& GetArForceByteSwapping() const;

public:
    uint8& GetArForceUnicode();
    const uint8& GetArForceUnicode() const;

public:
    uint32& GetArGameNetVer();
    const uint32& GetArGameNetVer() const;

public:
    uint8& GetArIgnoreArchetypeRef();
    const uint8& GetArIgnoreArchetypeRef() const;

public:
    uint8& GetArIgnoreClassGeneratedByRef();
    const uint8& GetArIgnoreClassGeneratedByRef() const;

public:
    uint8& GetArIgnoreClassRef();
    const uint8& GetArIgnoreClassRef() const;

public:
    uint8& GetArIgnoreOuterRef();
    const uint8& GetArIgnoreOuterRef() const;

public:
    uint8& GetArIsCountingMemory();
    const uint8& GetArIsCountingMemory() const;

public:
    uint8& GetArIsCriticalError();
    const uint8& GetArIsCriticalError() const;

public:
    uint8& GetArIsError();
    const uint8& GetArIsError() const;

public:
    uint8& GetArIsFilterEditorOnly();
    const uint8& GetArIsFilterEditorOnly() const;

public:
    uint8& GetArIsLoading();
    const uint8& GetArIsLoading() const;

public:
    uint8& GetArIsModifyingWeakAndStrongReferences();
    const uint8& GetArIsModifyingWeakAndStrongReferences() const;

public:
    uint8& GetArIsNetArchive();
    const uint8& GetArIsNetArchive() const;

public:
    uint8& GetArIsObjectReferenceCollector();
    const uint8& GetArIsObjectReferenceCollector() const;

public:
    uint8& GetArIsPersistent();
    const uint8& GetArIsPersistent() const;

public:
    uint8& GetArIsSaveGame();
    const uint8& GetArIsSaveGame() const;

public:
    uint8& GetArIsSaving();
    const uint8& GetArIsSaving() const;

public:
    uint8& GetArIsTextFormat();
    const uint8& GetArIsTextFormat() const;

public:
    uint8& GetArIsTransacting();
    const uint8& GetArIsTransacting() const;

public:
    int32& GetArLicenseeUE4Ver();
    const int32& GetArLicenseeUE4Ver() const;

public:
    int64& GetArMaxSerializeSize();
    const int64& GetArMaxSerializeSize() const;

public:
    int32& GetArNetVer();
    const int32& GetArNetVer() const;

public:
    uint8& GetArNoDelta();
    const uint8& GetArNoDelta() const;

public:
    uint8& GetArNoIntraPropertyDelta();
    const uint8& GetArNoIntraPropertyDelta() const;

public:
    uint32& GetArPortFlags();
    const uint32& GetArPortFlags() const;

public:
    uint8& GetArRequiresLocalizationGather();
    const uint8& GetArRequiresLocalizationGather() const;

public:
    int32& GetArSerializingDefaults();
    const int32& GetArSerializingDefaults() const;

public:
    uint8& GetArShouldSkipBulkData();
    const uint8& GetArShouldSkipBulkData() const;

public:
    int32& GetArUE4Ver();
    const int32& GetArUE4Ver() const;

public:
    uint8& GetArUseCustomPropertyList();
    const uint8& GetArUseCustomPropertyList() const;

public:
    uint8& GetArWantBinaryPropertySerialization();
    const uint8& GetArWantBinaryPropertySerialization() const;

public:
    ITargetPlatform*& GetCookingTargetPlatform();
    const ITargetPlatform*& GetCookingTargetPlatform() const;

public:
    FCustomVersionContainer*& GetCustomVersionContainer();
    const FCustomVersionContainer*& GetCustomVersionContainer() const;

public:
    FProperty*& GetSerializedProperty();
    const FProperty*& GetSerializedProperty() const;

public:
    bool& GetbCustomVersionsAreReset();
    const bool& GetbCustomVersionsAreReset() const;

