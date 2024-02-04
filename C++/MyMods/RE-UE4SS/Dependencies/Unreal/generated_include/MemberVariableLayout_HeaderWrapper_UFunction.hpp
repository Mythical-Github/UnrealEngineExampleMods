static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    int32& GetEventGraphCallOffset();
    const int32& GetEventGraphCallOffset() const;

public:
    UFunction*& GetEventGraphFunction();
    const UFunction*& GetEventGraphFunction() const;

public:
    FProperty*& GetFirstPropertyToInit();
    const FProperty*& GetFirstPropertyToInit() const;

public:
    void*& GetFunc();
    const void*& GetFunc() const;

public:
    EFunctionFlags& GetFunctionFlags();
    const EFunctionFlags& GetFunctionFlags() const;

public:
    uint8& GetNumParms();
    const uint8& GetNumParms() const;

public:
    uint16& GetParmsSize();
    const uint16& GetParmsSize() const;

public:
    uint16& GetRPCId();
    const uint16& GetRPCId() const;

public:
    uint16& GetRPCResponseId();
    const uint16& GetRPCResponseId() const;

public:
    uint16& GetRepOffset();
    const uint16& GetRepOffset() const;

public:
    uint16& GetReturnValueOffset();
    const uint16& GetReturnValueOffset() const;

