static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    UClass*& GetInterfaceClass();
    const UClass*& GetInterfaceClass() const;

