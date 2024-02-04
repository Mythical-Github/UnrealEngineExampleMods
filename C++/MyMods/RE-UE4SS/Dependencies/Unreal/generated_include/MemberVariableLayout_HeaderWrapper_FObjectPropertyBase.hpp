static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    UClass*& GetPropertyClass();
    const UClass*& GetPropertyClass() const;

