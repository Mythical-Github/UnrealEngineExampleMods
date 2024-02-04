static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    FField*& GetChildProperties();
    const FField*& GetChildProperties() const;

public:
    UField*& GetChildren();
    const UField*& GetChildren() const;

public:
    FProperty*& GetDestructorLink();
    const FProperty*& GetDestructorLink() const;

public:
    int32& GetMinAlignment();
    const int32& GetMinAlignment() const;

public:
    FProperty*& GetPostConstructLink();
    const FProperty*& GetPostConstructLink() const;

public:
    int32& GetPropertiesSize();
    const int32& GetPropertiesSize() const;

public:
    FProperty*& GetPropertyLink();
    const FProperty*& GetPropertyLink() const;

public:
    FProperty*& GetRefLink();
    const FProperty*& GetRefLink() const;

public:
    TArray<unsigned char,TSizedDefaultAllocator<32> >& GetScript();
    const TArray<unsigned char,TSizedDefaultAllocator<32> >& GetScript() const;

public:
    TArray<UObject *,TSizedDefaultAllocator<32> >& GetScriptAndPropertyObjectReferences();
    const TArray<UObject *,TSizedDefaultAllocator<32> >& GetScriptAndPropertyObjectReferences() const;

public:
    TArray<UObject *,TSizedDefaultAllocator<32> >& GetScriptObjectReferences();
    const TArray<UObject *,TSizedDefaultAllocator<32> >& GetScriptObjectReferences() const;

public:
    UStruct*& GetSuperStruct();
    const UStruct*& GetSuperStruct() const;

public:
    TArray<TTuple<TFieldPath<FField>,int>,TSizedDefaultAllocator<32> >*& GetUnresolvedScriptProperties();
    const TArray<TTuple<TFieldPath<FField>,int>,TSizedDefaultAllocator<32> >*& GetUnresolvedScriptProperties() const;

