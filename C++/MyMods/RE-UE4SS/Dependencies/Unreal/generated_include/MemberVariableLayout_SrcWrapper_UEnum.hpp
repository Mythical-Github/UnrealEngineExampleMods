std::unordered_map<File::StringType, int32_t> UEnum::MemberOffsets{};

UEnum::ECppForm& UEnum::GetCppForm()
{
    static auto offset = MemberOffsets.find(STR("CppForm"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::CppForm' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UEnum::ECppForm*>(this, offset->second);
}
const UEnum::ECppForm& UEnum::GetCppForm() const
{
    static auto offset = MemberOffsets.find(STR("CppForm"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::CppForm' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UEnum::ECppForm*>(this, offset->second);
}

FString& UEnum::GetCppType()
{
    static auto offset = MemberOffsets.find(STR("CppType"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::CppType' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FString*>(this, offset->second);
}
const FString& UEnum::GetCppType() const
{
    static auto offset = MemberOffsets.find(STR("CppType"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::CppType' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FString*>(this, offset->second);
}

FText*& UEnum::GetEnumDisplayNameFn()
{
    static auto offset = MemberOffsets.find(STR("EnumDisplayNameFn"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::EnumDisplayNameFn' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FText**>(this, offset->second);
}
const FText*& UEnum::GetEnumDisplayNameFn() const
{
    static auto offset = MemberOffsets.find(STR("EnumDisplayNameFn"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::EnumDisplayNameFn' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FText**>(this, offset->second);
}

EEnumFlags& UEnum::GetEnumFlags_Internal()
{
    static auto offset = MemberOffsets.find(STR("EnumFlags_Internal"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::EnumFlags_Internal' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<EEnumFlags*>(this, offset->second);
}
const EEnumFlags& UEnum::GetEnumFlags_Internal() const
{
    static auto offset = MemberOffsets.find(STR("EnumFlags_Internal"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::EnumFlags_Internal' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const EEnumFlags*>(this, offset->second);
}

FName& UEnum::GetEnumPackage()
{
    static auto offset = MemberOffsets.find(STR("EnumPackage"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::EnumPackage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& UEnum::GetEnumPackage() const
{
    static auto offset = MemberOffsets.find(STR("EnumPackage"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::EnumPackage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

TArray<TTuple<FName,__int64>,TSizedDefaultAllocator<32> >& UEnum::GetNames()
{
    static auto offset = MemberOffsets.find(STR("Names"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::Names' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<TTuple<FName,__int64>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<TTuple<FName,__int64>,TSizedDefaultAllocator<32> >& UEnum::GetNames() const
{
    static auto offset = MemberOffsets.find(STR("Names"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::Names' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<TTuple<FName,__int64>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

