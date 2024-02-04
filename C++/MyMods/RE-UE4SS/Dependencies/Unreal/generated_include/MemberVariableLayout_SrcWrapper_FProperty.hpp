std::unordered_map<File::StringType, int32_t> FProperty::MemberOffsets{};

int32& FProperty::GetArrayDim()
{
    static auto offset = MemberOffsets.find(STR("ArrayDim"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::ArrayDim' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& FProperty::GetArrayDim() const
{
    static auto offset = MemberOffsets.find(STR("ArrayDim"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::ArrayDim' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

FProperty*& FProperty::GetDestructorLinkNext()
{
    static auto offset = MemberOffsets.find(STR("DestructorLinkNext"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::DestructorLinkNext' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& FProperty::GetDestructorLinkNext() const
{
    static auto offset = MemberOffsets.find(STR("DestructorLinkNext"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::DestructorLinkNext' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

int32& FProperty::GetElementSize()
{
    static auto offset = MemberOffsets.find(STR("ElementSize"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::ElementSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& FProperty::GetElementSize() const
{
    static auto offset = MemberOffsets.find(STR("ElementSize"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::ElementSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

FProperty*& FProperty::GetNextRef()
{
    static auto offset = MemberOffsets.find(STR("NextRef"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::NextRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& FProperty::GetNextRef() const
{
    static auto offset = MemberOffsets.find(STR("NextRef"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::NextRef' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

int32& FProperty::GetOffset_Internal()
{
    static auto offset = MemberOffsets.find(STR("Offset_Internal"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::Offset_Internal' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& FProperty::GetOffset_Internal() const
{
    static auto offset = MemberOffsets.find(STR("Offset_Internal"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::Offset_Internal' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

FProperty*& FProperty::GetPostConstructLinkNext()
{
    static auto offset = MemberOffsets.find(STR("PostConstructLinkNext"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::PostConstructLinkNext' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& FProperty::GetPostConstructLinkNext() const
{
    static auto offset = MemberOffsets.find(STR("PostConstructLinkNext"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::PostConstructLinkNext' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

EPropertyFlags& FProperty::GetPropertyFlags()
{
    static auto offset = MemberOffsets.find(STR("PropertyFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::PropertyFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<EPropertyFlags*>(this, offset->second);
}
const EPropertyFlags& FProperty::GetPropertyFlags() const
{
    static auto offset = MemberOffsets.find(STR("PropertyFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::PropertyFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const EPropertyFlags*>(this, offset->second);
}

FProperty*& FProperty::GetPropertyLinkNext()
{
    static auto offset = MemberOffsets.find(STR("PropertyLinkNext"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::PropertyLinkNext' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& FProperty::GetPropertyLinkNext() const
{
    static auto offset = MemberOffsets.find(STR("PropertyLinkNext"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::PropertyLinkNext' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

uint16& FProperty::GetRepIndex()
{
    static auto offset = MemberOffsets.find(STR("RepIndex"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::RepIndex' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint16*>(this, offset->second);
}
const uint16& FProperty::GetRepIndex() const
{
    static auto offset = MemberOffsets.find(STR("RepIndex"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::RepIndex' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint16*>(this, offset->second);
}

FName& FProperty::GetRepNotifyFunc()
{
    static auto offset = MemberOffsets.find(STR("RepNotifyFunc"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::RepNotifyFunc' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& FProperty::GetRepNotifyFunc() const
{
    static auto offset = MemberOffsets.find(STR("RepNotifyFunc"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FProperty::RepNotifyFunc' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

