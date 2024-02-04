static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    UEnum*& GetEnum();
    const UEnum*& GetEnum() const;

