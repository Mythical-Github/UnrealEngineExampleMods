static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    UClass*& GetMetaClass();
    const UClass*& GetMetaClass() const;

