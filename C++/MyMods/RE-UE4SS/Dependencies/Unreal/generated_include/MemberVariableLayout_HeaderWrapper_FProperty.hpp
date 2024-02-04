static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    int32& GetArrayDim();
    const int32& GetArrayDim() const;

public:
    FProperty*& GetDestructorLinkNext();
    const FProperty*& GetDestructorLinkNext() const;

public:
    int32& GetElementSize();
    const int32& GetElementSize() const;

public:
    FProperty*& GetNextRef();
    const FProperty*& GetNextRef() const;

public:
    int32& GetOffset_Internal();
    const int32& GetOffset_Internal() const;

public:
    FProperty*& GetPostConstructLinkNext();
    const FProperty*& GetPostConstructLinkNext() const;

public:
    EPropertyFlags& GetPropertyFlags();
    const EPropertyFlags& GetPropertyFlags() const;

public:
    FProperty*& GetPropertyLinkNext();
    const FProperty*& GetPropertyLinkNext() const;

public:
    uint16& GetRepIndex();
    const uint16& GetRepIndex() const;

public:
    FName& GetRepNotifyFunc();
    const FName& GetRepNotifyFunc() const;

