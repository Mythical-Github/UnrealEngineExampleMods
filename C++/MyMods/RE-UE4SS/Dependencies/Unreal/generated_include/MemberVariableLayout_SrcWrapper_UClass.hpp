std::unordered_map<File::StringType, int32_t> UClass::MemberOffsets{};

void*& UClass::GetClassAddReferencedObjects()
{
    static auto offset = MemberOffsets.find(STR("ClassAddReferencedObjects"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassAddReferencedObjects' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<void**>(this, offset->second);
}
const void*& UClass::GetClassAddReferencedObjects() const
{
    static auto offset = MemberOffsets.find(STR("ClassAddReferencedObjects"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassAddReferencedObjects' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const void**>(this, offset->second);
}

uint64& UClass::GetClassCastFlags()
{
    static auto offset = MemberOffsets.find(STR("ClassCastFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassCastFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint64*>(this, offset->second);
}
const uint64& UClass::GetClassCastFlags() const
{
    static auto offset = MemberOffsets.find(STR("ClassCastFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassCastFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint64*>(this, offset->second);
}

FName& UClass::GetClassConfigName()
{
    static auto offset = MemberOffsets.find(STR("ClassConfigName"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassConfigName' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& UClass::GetClassConfigName() const
{
    static auto offset = MemberOffsets.find(STR("ClassConfigName"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassConfigName' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

void*& UClass::GetClassConstructor()
{
    static auto offset = MemberOffsets.find(STR("ClassConstructor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassConstructor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<void**>(this, offset->second);
}
const void*& UClass::GetClassConstructor() const
{
    static auto offset = MemberOffsets.find(STR("ClassConstructor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassConstructor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const void**>(this, offset->second);
}

UObject*& UClass::GetClassDefaultObject()
{
    static auto offset = MemberOffsets.find(STR("ClassDefaultObject"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassDefaultObject' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UObject**>(this, offset->second);
}
const UObject*& UClass::GetClassDefaultObject() const
{
    static auto offset = MemberOffsets.find(STR("ClassDefaultObject"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassDefaultObject' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UObject**>(this, offset->second);
}

EClassFlags& UClass::GetClassFlags()
{
    static auto offset = MemberOffsets.find(STR("ClassFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<EClassFlags*>(this, offset->second);
}
const EClassFlags& UClass::GetClassFlags() const
{
    static auto offset = MemberOffsets.find(STR("ClassFlags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassFlags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const EClassFlags*>(this, offset->second);
}

UObject*& UClass::GetClassGeneratedBy()
{
    static auto offset = MemberOffsets.find(STR("ClassGeneratedBy"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassGeneratedBy' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UObject**>(this, offset->second);
}
const UObject*& UClass::GetClassGeneratedBy() const
{
    static auto offset = MemberOffsets.find(STR("ClassGeneratedBy"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassGeneratedBy' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UObject**>(this, offset->second);
}

int32& UClass::GetClassUnique()
{
    static auto offset = MemberOffsets.find(STR("ClassUnique"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassUnique' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UClass::GetClassUnique() const
{
    static auto offset = MemberOffsets.find(STR("ClassUnique"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassUnique' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

UObject*& UClass::GetClassVTableHelperCtorCaller()
{
    static auto offset = MemberOffsets.find(STR("ClassVTableHelperCtorCaller"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassVTableHelperCtorCaller' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UObject**>(this, offset->second);
}
const UObject*& UClass::GetClassVTableHelperCtorCaller() const
{
    static auto offset = MemberOffsets.find(STR("ClassVTableHelperCtorCaller"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassVTableHelperCtorCaller' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UObject**>(this, offset->second);
}

UClass*& UClass::GetClassWithin()
{
    static auto offset = MemberOffsets.find(STR("ClassWithin"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassWithin' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UClass**>(this, offset->second);
}
const UClass*& UClass::GetClassWithin() const
{
    static auto offset = MemberOffsets.find(STR("ClassWithin"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::ClassWithin' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UClass**>(this, offset->second);
}

int32& UClass::GetFirstOwnedClassRep()
{
    static auto offset = MemberOffsets.find(STR("FirstOwnedClassRep"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::FirstOwnedClassRep' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& UClass::GetFirstOwnedClassRep() const
{
    static auto offset = MemberOffsets.find(STR("FirstOwnedClassRep"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::FirstOwnedClassRep' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

TArray<FImplementedInterface,TSizedDefaultAllocator<32> >& UClass::GetInterfaces()
{
    static auto offset = MemberOffsets.find(STR("Interfaces"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::Interfaces' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FImplementedInterface,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FImplementedInterface,TSizedDefaultAllocator<32> >& UClass::GetInterfaces() const
{
    static auto offset = MemberOffsets.find(STR("Interfaces"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::Interfaces' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FImplementedInterface,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

TArray<UField *,TSizedDefaultAllocator<32> >& UClass::GetNetFields()
{
    static auto offset = MemberOffsets.find(STR("NetFields"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::NetFields' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<UField *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<UField *,TSizedDefaultAllocator<32> >& UClass::GetNetFields() const
{
    static auto offset = MemberOffsets.find(STR("NetFields"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::NetFields' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<UField *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

void*& UClass::GetSparseClassData()
{
    static auto offset = MemberOffsets.find(STR("SparseClassData"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::SparseClassData' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<void**>(this, offset->second);
}
const void*& UClass::GetSparseClassData() const
{
    static auto offset = MemberOffsets.find(STR("SparseClassData"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::SparseClassData' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const void**>(this, offset->second);
}

UScriptStruct*& UClass::GetSparseClassDataStruct()
{
    static auto offset = MemberOffsets.find(STR("SparseClassDataStruct"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::SparseClassDataStruct' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UScriptStruct**>(this, offset->second);
}
const UScriptStruct*& UClass::GetSparseClassDataStruct() const
{
    static auto offset = MemberOffsets.find(STR("SparseClassDataStruct"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::SparseClassDataStruct' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UScriptStruct**>(this, offset->second);
}

FStructProperty*& UClass::GetUberGraphFramePointerProperty()
{
    static auto offset = MemberOffsets.find(STR("UberGraphFramePointerProperty"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::UberGraphFramePointerProperty' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FStructProperty**>(this, offset->second);
}
const FStructProperty*& UClass::GetUberGraphFramePointerProperty() const
{
    static auto offset = MemberOffsets.find(STR("UberGraphFramePointerProperty"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::UberGraphFramePointerProperty' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FStructProperty**>(this, offset->second);
}

bool& UClass::GetbCooked()
{
    static auto offset = MemberOffsets.find(STR("bCooked"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::bCooked' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UClass::GetbCooked() const
{
    static auto offset = MemberOffsets.find(STR("bCooked"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::bCooked' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

bool& UClass::GetbLayoutChanging()
{
    static auto offset = MemberOffsets.find(STR("bLayoutChanging"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::bLayoutChanging' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& UClass::GetbLayoutChanging() const
{
    static auto offset = MemberOffsets.find(STR("bLayoutChanging"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UClass::bLayoutChanging' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

