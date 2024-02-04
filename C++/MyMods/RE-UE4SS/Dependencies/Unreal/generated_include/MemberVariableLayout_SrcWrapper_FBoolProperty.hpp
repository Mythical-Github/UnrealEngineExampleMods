std::unordered_map<File::StringType, int32_t> FBoolProperty::MemberOffsets{};

uint8& FBoolProperty::GetByteMask()
{
    static auto offset = MemberOffsets.find(STR("ByteMask"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FBoolProperty::ByteMask' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FBoolProperty::GetByteMask() const
{
    static auto offset = MemberOffsets.find(STR("ByteMask"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FBoolProperty::ByteMask' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FBoolProperty::GetByteOffset()
{
    static auto offset = MemberOffsets.find(STR("ByteOffset"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FBoolProperty::ByteOffset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FBoolProperty::GetByteOffset() const
{
    static auto offset = MemberOffsets.find(STR("ByteOffset"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FBoolProperty::ByteOffset' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FBoolProperty::GetFieldMask()
{
    static auto offset = MemberOffsets.find(STR("FieldMask"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FBoolProperty::FieldMask' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FBoolProperty::GetFieldMask() const
{
    static auto offset = MemberOffsets.find(STR("FieldMask"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FBoolProperty::FieldMask' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& FBoolProperty::GetFieldSize()
{
    static auto offset = MemberOffsets.find(STR("FieldSize"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FBoolProperty::FieldSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& FBoolProperty::GetFieldSize() const
{
    static auto offset = MemberOffsets.find(STR("FieldSize"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FBoolProperty::FieldSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

