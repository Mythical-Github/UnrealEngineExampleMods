#include <Unreal/FField.hpp>
#include <Unreal/UClass.hpp>
#include <Unreal/UFunction.hpp>
#include <Unreal/FProperty.hpp>
#include <Unreal/VersionedContainer/Container.hpp>
#include <Helpers/Casting.hpp>

#define IMPLEMENT_FFIELD_VIRTUAL_WRAPPER(class_name, function_name, return_type, params, args) \
if (Version::IsBelow(4, 25)) \
{ \
    throw std::runtime_error{"FField virtual called in <4.25 and it has no equivalent virtual in <4.25"}; \
} \
IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(class_name, function_name, return_type, params, args)

#define IMPLEMENT_FFIELD_VIRTUAL_WRAPPER_NO_PARAMS(class_name, function_name, return_type) \
if (Version::is_below(4, 25)) \
{ \
    throw std::runtime_error{"FField virtual called in <4.25 and it has no equivalent virtual in <4.25"}; \
} \
IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(class_name, function_name, return_type)

namespace RC::Unreal
{
    IMPLEMENT_FIELD_CLASS(FField);

    bool Internal::FFieldTypeAccessor::TypeSystemInitialized = false;
    std::vector<void(*)()> Internal::FFieldTypeAccessor::LateBindCallbacks{};
    std::unordered_map<File::StringType, uint32_t> FField::VTableLayoutMap{};

#include <MemberVariableLayout_SrcWrapper_FField.hpp>

    auto Internal::FFieldTypeAccessor::GetObjectClass(FField* Field) -> FFieldClassVariant
    {
        return Field->GetClass();
    }

    auto Internal::FFieldTypeAccessor::GetClassSuperClass(FFieldClassVariant FieldClass) -> FFieldClassVariant
    {
        return FieldClass.GetSuperClass();
    }

    auto Internal::FFieldTypeAccessor::IsClassValid(FFieldClassVariant FieldClass) -> bool
    {
        return FieldClass.IsValid();
    }

    auto Internal::FFieldTypeAccessor::RegisterLateBindCallback(void (*Callback)()) -> void
    {
        if (!TypeSystemInitialized)
        {
            LateBindCallbacks.push_back(Callback);
        }
        else
        {
            Callback();
        }
    }

    auto Internal::FFieldTypeAccessor::OnTypeSystemInitialized() -> void
    {
        if (TypeSystemInitialized)
        {
            return;
        }
        TypeSystemInitialized = true;

        for (void (*callback)() : LateBindCallbacks)
        {
            callback();
        }
    }

    auto FField::GetClass() -> FFieldClassVariant
    {
        if (Version::IsBelow(4, 25))
        {
            return AsUFieldUnsafe()->GetClassPrivate();
        }
        else
        {
            return GetFFieldClassUnsafe();
        }
    }

    void FField::SetClass(FField* NewClass)
    {
        if (Version::IsBelow(4, 25))
        {
            AsUFieldUnsafe()->GetClassPrivate() = std::bit_cast<UClass*>(NewClass);
        }
        else
        {
            GetClassPrivate() = std::bit_cast<FFieldClass*>(NewClass);
        }
    }

    void FField::SetClass(UClass* NewClass)
    {
        if (Version::IsBelow(4, 25))
        {
            AsUFieldUnsafe()->GetClassPrivate() = NewClass;
        }
        else
        {
            GetClassPrivate() = std::bit_cast<FFieldClass*>(NewClass);
        }
    }

    auto FField::GetFName() -> FName
    {
        if (Version::IsBelow(4, 25))
        {
            return AsUFieldUnsafe()->GetNamePrivate();
        }
        else
        {
            return GetFFieldFNameUnsafe();
        }
    }

    File::StringType FField::GetFullName()
    {
        if (Version::IsAtLeast(4, 25 ))
        {
            File::StringType FullName = GetClass().GetName();
            FullName += STR(" ");
            FullName += GetPathName();
            return FullName;
        }
        else
        {
            return AsUFieldUnsafe()->GetFullName();
        }
    }

    File::StringType FField::GetPathName(UObject* StopOuter)
    {
        if (Version::IsAtLeast(4, 25))
        {
            File::StringType PathName;
            for (FFieldVariant TempOwner = GetOwnerVariant(); TempOwner.IsValid(); TempOwner = TempOwner.GetOwnerVariant())
            {
                if (!TempOwner.IsUObject())
                {
                    FField* FieldOwner = TempOwner.ToField();
                    PathName = FieldOwner->GetName() + STR(".") + PathName;
                }
                else
                {
                    UObject* ObjectOwner = TempOwner.ToUObject();
                    PathName += ObjectOwner->GetPathName(StopOuter);
                    PathName += SUBOBJECT_DELIMITER_CHAR;
                    break;
                }
            }
            PathName += GetName();
            return PathName;
        }
        else
        {
            return AsUFieldUnsafe()->GetPathName();
        }
    }

    auto FField::IsA(const FFieldClassVariant& UClass) -> bool
    {
        return GetClass().IsChildOf(UClass);
    }

    auto FField::GetOwnerVariant() -> FFieldVariant
    {
        if (Version::IsBelow(4, 25))
        {
            return AsUFieldUnsafe()->GetOuterPrivate();
        }
        else
        {
            return GetFFieldOwnerUnsafe();
        }
    }

    void FField::SetOwnerVariant(FField* field)
    {
        auto& OwnerVariant = GetOwner();
        if (Version::IsBelow(4, 25))
        {
            // Safe because in <4.25 all fields inherit from UObject
            OwnerVariant.Set(std::bit_cast<UObject*>(field));
        }
        else
        {
            OwnerVariant.Set(field);
        }
    }

    void FField::SetOwnerVariant(UObject* object)
    {
        auto& OwnerVariant = GetOwner();
        if (Version::IsBelow(4, 25))
        {
            // Safe because in <4.25 all fields inherit from UObject
            OwnerVariant.Set(std::bit_cast<FField*>(object));
        }
        else
        {
            OwnerVariant.Set(object);
        }
    }

    UObject* FField::GetOutermostOwner()
    {
        auto CurrentVariant = GetOwnerVariant();

        while (!CurrentVariant.IsUObject())
        {
            CurrentVariant = CurrentVariant.GetOwnerVariant();
        }

        return CurrentVariant.ToUObject();
    }

    auto FField::GetTypedOwner(UClass* OwnerType) -> UObject*
    {
        FFieldVariant CurrentVariant = GetOwnerVariant();

        while (CurrentVariant.IsValid()) {
            if (CurrentVariant.IsUObject())
            {
                return CurrentVariant.ToUObject()->GetTypedOuter(OwnerType);
            }
            CurrentVariant = CurrentVariant.GetOwnerVariant();
        }
        return nullptr;
    }

    bool FField::HasNext()
    {
        if (Version::IsBelow(4, 25))
        {
            return AsUFieldUnsafe()->GetNext();
        }
        else
        {
            return GetNextFFieldUnsafe();
        }
    }

    FProperty* FField::GetNextFieldAsProperty()
    {
        // In <4.25, we can cast to a property because all properties inherits from UField
        // In <4.25, this FField struct represents UField
        // In 4.25+, properties inherit from FField so there's no problem with this cast
        if (Version::IsBelow(4, 25))
        {
            return std::bit_cast<FProperty*>(AsUFieldUnsafe()->GetNext());
        }
        else
        {
            return CastField<FProperty>(GetNext()); 
        }
    }

    auto FField::AsUFieldUnsafe() -> UField*
    {
        if (!Version::IsBelow(4, 25))
        {
            throw std::runtime_error("FField does not inherit from UObject in UE4.25+");
        }
        return std::bit_cast<UField*>(this);
    }


    auto FField::AsUFieldUnsafe() const -> const UField*
    {
        if (!Version::IsBelow(4, 25))
        {
            throw std::runtime_error("FField does not inherit from UObject in UE4.25+");
        }
        return std::bit_cast<const UField*>(this);
    }

    auto FField::GetFFieldClassUnsafe() -> FFieldClass*
    {
        if (Version::IsBelow(4, 25))
        {
            throw std::runtime_error("FFieldClass is not available in UE versions below 4.25");
        }
        return GetClassPrivate();
    }

    auto FField::GetFFieldOwnerUnsafe() -> FFieldVariant
    {
        if (Version::IsBelow(4, 25))
        {
            throw std::runtime_error("FField::Owner is not available in UE versions below 4.25");
        }
        return GetOwner();
    }

    auto FField::GetFFieldFNameUnsafe() -> FName
    {
        if (Version::IsBelow(4, 25))
        {
            throw std::runtime_error("FField::FName is not available in UE versions below 4.25");
        }
        return GetNamePrivate();
    }

    auto FField::Serialize(FArchive& Ar) -> void
    {
        if (Version::IsAtLeast(4, 25))
        {
            IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FField, Serialize, void, PARAMS(FArchive & ), ARGS(Ar))
        }
        else
        {
            // In <4.25, all FField instances in UE4SS is actually UField
            // Since UProperty inherits from UField, we must redirect virtual calls to UField and UObject
            AsUFieldUnsafe()->Serialize(Ar);
        }
    }

    auto FField::PostLoad() -> void
    {
        if (Version::IsAtLeast(4, 25))
        {
            IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FField, PostLoad, void)
        }
        else
        {
            // In <4.25, all FField instances in UE4SS is actually UField
            // Since UProperty inherits from UField, we must redirect virtual calls to UField and UObject
            AsUFieldUnsafe()->PostLoad();
        }
    }

    auto FField::GetPreloadDependencies(TArray<UObject*>& OutDeps) -> void
    {
        if (Version::IsAtLeast(4, 25))
        {
            IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FField, GetPreloadDependencies, void, PARAMS(TArray<UObject*> & ), ARGS(OutDeps))
        }
        else
        {
            AsUFieldUnsafe()->GetPreloadDependencies(OutDeps);
        }
    }

    auto FField::BeginDestroy() -> void
    {
        if (Version::IsAtLeast(4, 25))
        {
            IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FField, BeginDestroy, void)
        }
        else
        {
            AsUFieldUnsafe()->BeginDestroy();
        }
    }

    using FReferenceCollector = void*; // Remove if/when we have an FArchive implementation, for now, probably a bad idea to call
    auto FField::AddReferencedObjects(FReferenceCollector& Collector) -> void
    {
        IMPLEMENT_FFIELD_VIRTUAL_WRAPPER(FField, AddReferencedObjects, void, PARAMS(FReferenceCollector&), ARGS(Collector))
    }

    auto FField::AddCppProperty(FProperty* Property) -> void
    {
        if (Version::IsAtLeast(4, 25))
        {
            IMPLEMENT_UNREAL_VIRTUAL_WRAPPER(FField, AddCppProperty, void, PARAMS(FProperty*), ARGS(Property))
        }
        else
        {
            // In <4.25, all FField instances in UE4SS is actually UField
            // Since UProperty inherits from UField, we must redirect virtual calls to UField and UObject
            AsUFieldUnsafe()->AddCppProperty(Property);
        }
    }

    auto FField::Bind() -> void
    {
        if (Version::IsAtLeast(4, 25))
        {
            IMPLEMENT_UNREAL_VIRTUAL_WRAPPER_NO_PARAMS(FField, Bind, void)
        }
        else
        {
            // In <4.25, all FField instances in UE4SS is actually UField
            // Since UProperty inherits from UField, we must redirect virtual calls to UField and UObject
            AsUFieldUnsafe()->Bind();
        }
    }

    auto FField::PostDuplicate(const FField& InField) -> void
    {
        IMPLEMENT_FFIELD_VIRTUAL_WRAPPER(FField, PostDuplicate, void, PARAMS(const FField&), ARGS(InField))
    }

    auto FField::GetInnerFieldByName(const FName& InName) -> FField*
    {
        IMPLEMENT_FFIELD_VIRTUAL_WRAPPER(FField, GetInnerFieldByName, FField*, PARAMS(const FName&), ARGS(InName))
    }

    auto FField::GetInnerFields(TArray<FField*>& OutFields) -> void
    {
        IMPLEMENT_FFIELD_VIRTUAL_WRAPPER(FField, GetInnerFields, void, PARAMS(TArray<FField*>&), ARGS(OutFields))
    }

    void FField::PostDuplicate(bool bDuplicateForPIE)
    {
        if (Version::IsAtLeast(4, 25))
        {
            throw std::runtime_error{"FField::PostDuplicate overload with bool param is only allowed to be called in <4.25"};
        }
        else
        {
            AsUFieldUnsafe()->PostDuplicate(bDuplicateForPIE);
        }
    }

    bool FField::NeedsLoadForClient() const
    {
        if (Version::IsAtLeast(4, 25))
        {
            throw std::runtime_error{"FField::NeedsLoadForClient is only allowed to be called in <4.25"};
        }
        else
        {
            return AsUFieldUnsafe()->NeedsLoadForClient();
        }
    };

    bool FField::NeedsLoadForServer() const
    {
        if (Version::IsAtLeast(4, 25))
        {
            throw std::runtime_error{"FField::NeedsLoadForServer is only allowed to be called in <4.25"};
        }
        else
        {
            return AsUFieldUnsafe()->NeedsLoadForServer();
        }
    };

    auto FField::GetNextFFieldUnsafe() -> FField*
    {
        if (Version::IsBelow(4, 25))
        {
            throw std::runtime_error("FField::Next is not available in UE versions below 4.25");
        }
        return GetNext();
    }

    FFieldClassVariant::FFieldClassVariant(FFieldClass* Field) : IsObject(false)
    {
        Container.Field = Field;
    }

    FFieldClassVariant::FFieldClassVariant(UClass* Object) : IsObject(true)
    {
        Container.Object = Object;
    }

    FFieldClassVariant::FFieldClassVariant(const UClass* Object) : IsObject(true)
    {
        Container.Object = Object;
    }

    FFieldClassVariant::FFieldClassVariant() : IsObject(false)
    {
        Container.Field = nullptr;
    }

    auto FFieldClassVariant::IsValid() const -> bool
    {
        return Container.Object;
    }

    auto FFieldClassVariant::IsUClass() const -> bool
    {
        return IsValid() && IsObject;
    }

    auto FFieldClassVariant::IsFieldClass() const -> bool
    {
        return IsValid() && !IsObject;
    }

    auto FFieldClassVariant::ToFieldClass() const -> FFieldClass*
    {
        if (IsFieldClass())
        {
            return Container.Field;
        }
        else
        {
            throw std::runtime_error("FFieldClassVariant does not represent a FFieldClass");
        }
    }

    auto FFieldClassVariant::ToUClass() const -> const UClass*
    {
        if (IsUClass())
        {
            return Container.Object;
        }
        else
        {
            throw std::runtime_error("FFieldClassVariant does not represent a UClass");
        }
    }

    auto FFieldClassVariant::GetFName() const -> FName {
        if (IsUClass())
        {
            return ToUClass()->GetNamePrivate();
        }
        else
        {
            return ToFieldClass()->GetFName();
        }
    }

    auto FFieldClassVariant::GetSuperClass() const -> FFieldClassVariant
    {
        if (IsUClass())
        {
            return ToUClass()->GetSuperClass();
        }
        else
        {
            return ToFieldClass()->GetSuperClass();
        }
    }

    auto FFieldClassVariant::IsChildOf(FFieldClassVariant UClass) const -> bool
    {
        //Comparisons between UClass and FFieldClass never return true
        if (IsUClass() != UClass.IsUClass())
        {
            return false;
        }

        if (IsUClass())
        {
            return ToUClass()->IsChildOf(UClass.ToUClass());
        }
        else
        {
            return ToFieldClass()->IsChildOf(UClass.ToFieldClass());
        }
    }

    EClassCastFlags FFieldClassVariant::GetClassCastFlags() const
    {
        if (IsUClass())
        {
            return static_cast<EClassCastFlags>(ToUClass()->GetClassCastFlags());
        }
        else
        {
            return static_cast<EClassCastFlags>(ToFieldClass()->CastFlags);
        }
    }

    void FFieldClassVariant::Set(FFieldClass* FieldClass)
    {
        Container.Field = FieldClass;
    }

    void FFieldClassVariant::Set(UClass* Object)
    {
        Container.Object = Object;
    }

    void FFieldClassVariant::Set(const UClass* Object)
    {
        Container.Object = Object;
    }

    auto FFieldClassVariant::operator==(const RC::Unreal::FFieldClassVariant& Rhs) const -> bool {
        if (!IsValid() || !Rhs.IsValid())
        {
            return false;
        }
        if (IsUClass() != Rhs.IsUClass())
        {
            return false;
        }
        if (IsUClass())
        {
            return ToUClass() == Rhs.ToUClass();
        }
        else
        {
            return ToFieldClass() == Rhs.ToFieldClass();
        }
    }

    auto FFieldClassVariant::HashObject() const -> size_t
    {
        if (!IsValid())
        {
            return 0;
        }
        if (IsUClass())
        {
            return reinterpret_cast<size_t>(ToUClass());
        }
        else
        {
            return reinterpret_cast<size_t>(ToFieldClass());
        }
    }

    auto FFieldClass::GetFName() const -> FName
    {
        return Name;
    }

    auto FFieldClass::GetSuperClass() const -> FFieldClass*
    {
        return SuperClass;
    }

    auto FFieldClass::IsChildOf(FFieldClass* FieldClass) const -> bool
    {
        const FFieldClass* CurrentClass = this;
        do {
            if (CurrentClass == FieldClass)
            {
                return true;
            }
            CurrentClass = CurrentClass->GetSuperClass();
        }
        while (CurrentClass);
        return false;
    }

    auto FFieldVariant::GetOwnerVariant() -> FFieldVariant
    {
        if (IsUObject())
        {
            return Container.Object->GetOuterPrivate();
        }
        else
        {
            return Container.Field->GetOwnerVariant();
        }
    }

    void FFieldVariant::Set(FField* Field)
    {
        if (Version::IsAtLeast(4, 25))
        {
            IsObject = false;
        }
        Container.Field = Field;
    }

    void FFieldVariant::Set(UObject* Object)
    {
        if (Version::IsAtLeast(4, 25))
        {
            IsObject = true;
        }
        Container.Object = Object;
    }

    auto FFieldVariant::HashObject() -> size_t
    {
        if (!IsValid())
        {
            return 0;
        }
        if (IsUObject())
        {
            return reinterpret_cast<size_t>(ToUObject());
        }
        else
        {
            return reinterpret_cast<size_t>(ToField());
        }
    }
}
