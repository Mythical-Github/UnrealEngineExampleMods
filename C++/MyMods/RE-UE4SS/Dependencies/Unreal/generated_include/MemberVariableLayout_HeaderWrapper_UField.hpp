static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    UField*& GetNext();
    const UField*& GetNext() const;

