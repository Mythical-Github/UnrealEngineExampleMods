static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    UScriptStruct*& GetStruct();
    const UScriptStruct*& GetStruct() const;

