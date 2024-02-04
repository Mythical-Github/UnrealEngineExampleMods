static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    int32& GetAlignment();
    const int32& GetAlignment() const;

public:
    int32& GetSize();
    const int32& GetSize() const;

