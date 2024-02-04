static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    void*& GetClassAddReferencedObjects();
    const void*& GetClassAddReferencedObjects() const;

public:
    uint64& GetClassCastFlags();
    const uint64& GetClassCastFlags() const;

public:
    FName& GetClassConfigName();
    const FName& GetClassConfigName() const;

public:
    void*& GetClassConstructor();
    const void*& GetClassConstructor() const;

public:
    UObject*& GetClassDefaultObject();
    const UObject*& GetClassDefaultObject() const;

public:
    EClassFlags& GetClassFlags();
    const EClassFlags& GetClassFlags() const;

public:
    UObject*& GetClassGeneratedBy();
    const UObject*& GetClassGeneratedBy() const;

public:
    int32& GetClassUnique();
    const int32& GetClassUnique() const;

public:
    UObject*& GetClassVTableHelperCtorCaller();
    const UObject*& GetClassVTableHelperCtorCaller() const;

public:
    UClass*& GetClassWithin();
    const UClass*& GetClassWithin() const;

public:
    int32& GetFirstOwnedClassRep();
    const int32& GetFirstOwnedClassRep() const;

public:
    TArray<FImplementedInterface,TSizedDefaultAllocator<32> >& GetInterfaces();
    const TArray<FImplementedInterface,TSizedDefaultAllocator<32> >& GetInterfaces() const;

public:
    TArray<UField *,TSizedDefaultAllocator<32> >& GetNetFields();
    const TArray<UField *,TSizedDefaultAllocator<32> >& GetNetFields() const;

public:
    void*& GetSparseClassData();
    const void*& GetSparseClassData() const;

public:
    UScriptStruct*& GetSparseClassDataStruct();
    const UScriptStruct*& GetSparseClassDataStruct() const;

public:
    FStructProperty*& GetUberGraphFramePointerProperty();
    const FStructProperty*& GetUberGraphFramePointerProperty() const;

public:
    bool& GetbCooked();
    const bool& GetbCooked() const;

public:
    bool& GetbLayoutChanging();
    const bool& GetbLayoutChanging() const;

