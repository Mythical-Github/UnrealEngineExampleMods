std::unordered_map<File::StringType, int32_t> FField::MemberOffsets{};

FFieldClass*& FField::GetClassPrivate()
{
    static auto offset = MemberOffsets.find(STR("ClassPrivate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FField::ClassPrivate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FFieldClass**>(this, offset->second);
}
const FFieldClass*& FField::GetClassPrivate() const
{
    static auto offset = MemberOffsets.find(STR("ClassPrivate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FField::ClassPrivate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FFieldClass**>(this, offset->second);
}

EObjectFlags& FField::GetFlagsPrivate()
{
    static auto offset = MemberOffsets.find(STR("FlagsPrivate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FField::FlagsPrivate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<EObjectFlags*>(this, offset->second);
}
const EObjectFlags& FField::GetFlagsPrivate() const
{
    static auto offset = MemberOffsets.find(STR("FlagsPrivate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FField::FlagsPrivate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const EObjectFlags*>(this, offset->second);
}

FName& FField::GetNamePrivate()
{
    static auto offset = MemberOffsets.find(STR("NamePrivate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FField::NamePrivate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& FField::GetNamePrivate() const
{
    static auto offset = MemberOffsets.find(STR("NamePrivate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FField::NamePrivate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

FField*& FField::GetNext()
{
    static auto offset = MemberOffsets.find(STR("Next"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FField::Next' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FField**>(this, offset->second);
}
const FField*& FField::GetNext() const
{
    static auto offset = MemberOffsets.find(STR("Next"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FField::Next' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FField**>(this, offset->second);
}

FFieldVariant& FField::GetOwner()
{
    static auto offset = MemberOffsets.find(STR("Owner"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FField::Owner' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FFieldVariant*>(this, offset->second);
}
const FFieldVariant& FField::GetOwner() const
{
    static auto offset = MemberOffsets.find(STR("Owner"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'FField::Owner' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FFieldVariant*>(this, offset->second);
}

