std::unordered_map<File::StringType, int32_t> UStruct::MemberOffsets{};

FField*& UStruct::GetChildProperties()
{
    static auto offset = MemberOffsets.find(STR("ChildProperties"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::ChildProperties' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FField**>(this, offset->second);
}
const FField*& UStruct::GetChildProperties() const
{
    static auto offset = MemberOffsets.find(STR("ChildProperties"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::ChildProperties' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FField**>(this, offset->second);
}

UField*& UStruct::GetChildren()
{
    static auto offset = MemberOffsets.find(STR("Children"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::Children' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UField**>(this, offset->second);
}
const UField*& UStruct::GetChildren() const
{
    static auto offset = MemberOffsets.find(STR("Children"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::Children' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UField**>(this, offset->second);
}

FProperty*& UStruct::GetDestructorLink()
{
    static auto offset = MemberOffsets.find(STR("DestructorLink"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::DestructorLink' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& UStruct::GetDestructorLink() const
{
    static auto offset = MemberOffsets.find(STR("DestructorLink"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::DestructorLink' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

int32& UStruct::GetMinAlignment()
{
    static auto offset = MemberOffsets.find(STR("MinAlignment"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::MinAlignment' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UStruct::GetMinAlignment() const
{
    static auto offset = MemberOffsets.find(STR("MinAlignment"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::MinAlignment' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

FProperty*& UStruct::GetPostConstructLink()
{
    static auto offset = MemberOffsets.find(STR("PostConstructLink"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::PostConstructLink' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& UStruct::GetPostConstructLink() const
{
    static auto offset = MemberOffsets.find(STR("PostConstructLink"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::PostConstructLink' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

int32& UStruct::GetPropertiesSize()
{
    static auto offset = MemberOffsets.find(STR("PropertiesSize"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::PropertiesSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UStruct::GetPropertiesSize() const
{
    static auto offset = MemberOffsets.find(STR("PropertiesSize"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::PropertiesSize' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

FProperty*& UStruct::GetPropertyLink()
{
    static auto offset = MemberOffsets.find(STR("PropertyLink"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::PropertyLink' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& UStruct::GetPropertyLink() const
{
    static auto offset = MemberOffsets.find(STR("PropertyLink"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::PropertyLink' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

FProperty*& UStruct::GetRefLink()
{
    static auto offset = MemberOffsets.find(STR("RefLink"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::RefLink' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FProperty**>(this, offset->second);
}
const FProperty*& UStruct::GetRefLink() const
{
    static auto offset = MemberOffsets.find(STR("RefLink"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::RefLink' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FProperty**>(this, offset->second);
}

TArray<unsigned char,TSizedDefaultAllocator<32> >& UStruct::GetScript()
{
    static auto offset = MemberOffsets.find(STR("Script"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::Script' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<unsigned char,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<unsigned char,TSizedDefaultAllocator<32> >& UStruct::GetScript() const
{
    static auto offset = MemberOffsets.find(STR("Script"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::Script' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<unsigned char,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

TArray<UObject *,TSizedDefaultAllocator<32> >& UStruct::GetScriptAndPropertyObjectReferences()
{
    static auto offset = MemberOffsets.find(STR("ScriptAndPropertyObjectReferences"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::ScriptAndPropertyObjectReferences' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<UObject *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<UObject *,TSizedDefaultAllocator<32> >& UStruct::GetScriptAndPropertyObjectReferences() const
{
    static auto offset = MemberOffsets.find(STR("ScriptAndPropertyObjectReferences"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::ScriptAndPropertyObjectReferences' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<UObject *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

TArray<UObject *,TSizedDefaultAllocator<32> >& UStruct::GetScriptObjectReferences()
{
    static auto offset = MemberOffsets.find(STR("ScriptObjectReferences"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::ScriptObjectReferences' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<UObject *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<UObject *,TSizedDefaultAllocator<32> >& UStruct::GetScriptObjectReferences() const
{
    static auto offset = MemberOffsets.find(STR("ScriptObjectReferences"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::ScriptObjectReferences' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<UObject *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

UStruct*& UStruct::GetSuperStruct()
{
    static auto offset = MemberOffsets.find(STR("SuperStruct"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::SuperStruct' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UStruct**>(this, offset->second);
}
const UStruct*& UStruct::GetSuperStruct() const
{
    static auto offset = MemberOffsets.find(STR("SuperStruct"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::SuperStruct' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UStruct**>(this, offset->second);
}

TArray<TTuple<TFieldPath<FField>,int>,TSizedDefaultAllocator<32> >*& UStruct::GetUnresolvedScriptProperties()
{
    static auto offset = MemberOffsets.find(STR("UnresolvedScriptProperties"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::UnresolvedScriptProperties' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<TTuple<TFieldPath<FField>,int>,TSizedDefaultAllocator<32> >**>(this, offset->second);
}
const TArray<TTuple<TFieldPath<FField>,int>,TSizedDefaultAllocator<32> >*& UStruct::GetUnresolvedScriptProperties() const
{
    static auto offset = MemberOffsets.find(STR("UnresolvedScriptProperties"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UStruct::UnresolvedScriptProperties' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<TTuple<TFieldPath<FField>,int>,TSizedDefaultAllocator<32> >**>(this, offset->second);
}

