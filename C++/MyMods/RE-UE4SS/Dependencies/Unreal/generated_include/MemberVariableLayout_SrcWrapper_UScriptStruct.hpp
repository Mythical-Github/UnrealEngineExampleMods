std::unordered_map<File::StringType, int32_t> UScriptStruct::MemberOffsets{};

UScriptStruct::ICppStructOps*& UScriptStruct::GetCppStructOps()
{
    static auto offset = MemberOffsets.find(STR("CppStructOps"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::CppStructOps' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UScriptStruct::ICppStructOps**>(this, offset->second);
}
const UScriptStruct::ICppStructOps*& UScriptStruct::GetCppStructOps() const
{
    static auto offset = MemberOffsets.find(STR("CppStructOps"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::CppStructOps' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UScriptStruct::ICppStructOps**>(this, offset->second);
}

EStructFlags& UScriptStruct::GetStructFlags()
{
    static auto offset = MemberOffsets.find(STR("StructFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::StructFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<EStructFlags*>(this, offset->second);
}
const EStructFlags& UScriptStruct::GetStructFlags() const
{
    static auto offset = MemberOffsets.find(STR("StructFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::StructFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const EStructFlags*>(this, offset->second);
}

bool& UScriptStruct::GetbCppStructOpsFromBaseClass()
{
    static auto offset = MemberOffsets.find(STR("bCppStructOpsFromBaseClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::bCppStructOpsFromBaseClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UScriptStruct::GetbCppStructOpsFromBaseClass() const
{
    static auto offset = MemberOffsets.find(STR("bCppStructOpsFromBaseClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::bCppStructOpsFromBaseClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

bool& UScriptStruct::GetbPrepareCppStructOpsCompleted()
{
    static auto offset = MemberOffsets.find(STR("bPrepareCppStructOpsCompleted"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::bPrepareCppStructOpsCompleted' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UScriptStruct::GetbPrepareCppStructOpsCompleted() const
{
    static auto offset = MemberOffsets.find(STR("bPrepareCppStructOpsCompleted"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UScriptStruct::bPrepareCppStructOpsCompleted' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

