std::unordered_map<File::StringType, int32_t> UFunction::MemberOffsets{};

int32& UFunction::GetEventGraphCallOffset()
{
    static auto offset = MemberOffsets.find(STR("EventGraphCallOffset"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::EventGraphCallOffset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UFunction::GetEventGraphCallOffset() const
{
    static auto offset = MemberOffsets.find(STR("EventGraphCallOffset"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::EventGraphCallOffset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

UFunction*& UFunction::GetEventGraphFunction()
{
    static auto offset = MemberOffsets.find(STR("EventGraphFunction"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::EventGraphFunction' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UFunction**>(this, offset->second);
}
const UFunction*& UFunction::GetEventGraphFunction() const
{
    static auto offset = MemberOffsets.find(STR("EventGraphFunction"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::EventGraphFunction' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UFunction**>(this, offset->second);
}

FProperty*& UFunction::GetFirstPropertyToInit()
{
    static auto offset = MemberOffsets.find(STR("FirstPropertyToInit"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::FirstPropertyToInit' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& UFunction::GetFirstPropertyToInit() const
{
    static auto offset = MemberOffsets.find(STR("FirstPropertyToInit"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::FirstPropertyToInit' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

void*& UFunction::GetFunc()
{
    static auto offset = MemberOffsets.find(STR("Func"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::Func' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<void**>(this, offset->second);
}
const void*& UFunction::GetFunc() const
{
    static auto offset = MemberOffsets.find(STR("Func"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::Func' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const void**>(this, offset->second);
}

EFunctionFlags& UFunction::GetFunctionFlags()
{
    static auto offset = MemberOffsets.find(STR("FunctionFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::FunctionFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<EFunctionFlags*>(this, offset->second);
}
const EFunctionFlags& UFunction::GetFunctionFlags() const
{
    static auto offset = MemberOffsets.find(STR("FunctionFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::FunctionFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const EFunctionFlags*>(this, offset->second);
}

uint8& UFunction::GetNumParms()
{
    static auto offset = MemberOffsets.find(STR("NumParms"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::NumParms' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& UFunction::GetNumParms() const
{
    static auto offset = MemberOffsets.find(STR("NumParms"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::NumParms' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint16& UFunction::GetParmsSize()
{
    static auto offset = MemberOffsets.find(STR("ParmsSize"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::ParmsSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint16*>(this, offset->second);
}
const uint16& UFunction::GetParmsSize() const
{
    static auto offset = MemberOffsets.find(STR("ParmsSize"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::ParmsSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint16*>(this, offset->second);
}

uint16& UFunction::GetRPCId()
{
    static auto offset = MemberOffsets.find(STR("RPCId"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::RPCId' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint16*>(this, offset->second);
}
const uint16& UFunction::GetRPCId() const
{
    static auto offset = MemberOffsets.find(STR("RPCId"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::RPCId' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint16*>(this, offset->second);
}

uint16& UFunction::GetRPCResponseId()
{
    static auto offset = MemberOffsets.find(STR("RPCResponseId"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::RPCResponseId' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint16*>(this, offset->second);
}
const uint16& UFunction::GetRPCResponseId() const
{
    static auto offset = MemberOffsets.find(STR("RPCResponseId"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::RPCResponseId' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint16*>(this, offset->second);
}

uint16& UFunction::GetRepOffset()
{
    static auto offset = MemberOffsets.find(STR("RepOffset"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::RepOffset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint16*>(this, offset->second);
}
const uint16& UFunction::GetRepOffset() const
{
    static auto offset = MemberOffsets.find(STR("RepOffset"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::RepOffset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint16*>(this, offset->second);
}

uint16& UFunction::GetReturnValueOffset()
{
    static auto offset = MemberOffsets.find(STR("ReturnValueOffset"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::ReturnValueOffset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint16*>(this, offset->second);
}
const uint16& UFunction::GetReturnValueOffset() const
{
    static auto offset = MemberOffsets.find(STR("ReturnValueOffset"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UFunction::ReturnValueOffset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint16*>(this, offset->second);
}

