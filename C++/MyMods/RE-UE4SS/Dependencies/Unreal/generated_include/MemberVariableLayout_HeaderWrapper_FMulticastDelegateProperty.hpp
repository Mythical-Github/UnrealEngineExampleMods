static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    UFunction*& GetSignatureFunction();
    const UFunction*& GetSignatureFunction() const;

