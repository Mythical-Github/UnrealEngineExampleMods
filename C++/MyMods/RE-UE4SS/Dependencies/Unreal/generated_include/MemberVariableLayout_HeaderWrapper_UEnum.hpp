static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    UEnum::ECppForm& GetCppForm();
    const UEnum::ECppForm& GetCppForm() const;

public:
    FString& GetCppType();
    const FString& GetCppType() const;

public:
    FText*& GetEnumDisplayNameFn();
    const FText*& GetEnumDisplayNameFn() const;

private:
    EEnumFlags& GetEnumFlags_Internal();
    const EEnumFlags& GetEnumFlags_Internal() const;

public:
    FName& GetEnumPackage();
    const FName& GetEnumPackage() const;

public:
    TArray<TTuple<FName,__int64>,TSizedDefaultAllocator<32> >& GetNames();
    const TArray<TTuple<FName,__int64>,TSizedDefaultAllocator<32> >& GetNames() const;

