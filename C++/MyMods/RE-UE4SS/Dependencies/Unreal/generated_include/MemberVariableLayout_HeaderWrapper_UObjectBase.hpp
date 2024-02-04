static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    UClass*& GetClass();
    const UClass*& GetClass() const;

public:
    UClass*& GetClassPrivate();
    const UClass*& GetClassPrivate() const;

public:
    //int32& GetInternalIndex();
    //const int32& GetInternalIndex() const;

public:
    FName& GetName();
    const FName& GetName() const;

public:
    FName& GetNamePrivate();
    const FName& GetNamePrivate() const;

public:
    EObjectFlags& GetObjectFlags();
    const EObjectFlags& GetObjectFlags() const;

public:
    UObject*& GetOuter();
    const UObject*& GetOuter() const;

public:
    UObject*& GetOuterPrivate();
    const UObject*& GetOuterPrivate() const;

