static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    FProperty*& GetInner();
    const FProperty*& GetInner() const;

