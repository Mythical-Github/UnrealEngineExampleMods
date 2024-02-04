static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    FProperty*& GetElementProp();
    const FProperty*& GetElementProp() const;

