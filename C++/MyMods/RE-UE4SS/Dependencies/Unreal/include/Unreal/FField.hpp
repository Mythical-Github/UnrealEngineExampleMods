#ifndef RC_UNREAL_FFIELD_HPP
#define RC_UNREAL_FFIELD_HPP

#include <Constructs/Loop.hpp>
#include <Unreal/Common.hpp>
#include <Unreal/UObjectMacros.hpp>
#include <Unreal/NameTypes.hpp>
#include <Unreal/ContainersFwd.hpp>
#include <Unreal/UnrealVersion.hpp>
#include <Unreal/TypeChecker.hpp>
#include <Unreal/VirtualFunctionHelper.hpp>
#include <Unreal/FArchive.hpp>

namespace RC::Unreal
{
    class UClass;
    class UStruct;
    class FField;
    class FProperty;
    class FFieldVariant;
    class RC_UE_API FFieldClassVariant;
    class FFieldClass;

    template<typename SupposedFField>
    concept FFieldDerivative = std::is_convertible_v<SupposedFField, ::RC::Unreal::FField>;

    namespace Internal {
        class FFieldTypeAccessor;
    }

    /**
     * Represents an FField object on the UE versions above UE4.25
     * On the earlier versions it will be falling back to the UField behavior, allowing the version
     * independent data to the FField data, which is primarily used for working with FProperties
     *
     * This class CANNOT be used to represent UField* objects on UE 4.25+, use UField instead!!
     */
    class RC_UE_API FField
    {
        DECLARE_FIELD_CLASS(FField);
        DECLARE_VIRTUAL_TYPE_BASE(FField, Internal::FFieldTypeAccessor);

    public:
        static std::unordered_map<File::StringType, uint32_t> VTableLayoutMap;

    public:
#include <MemberVariableLayout_HeaderWrapper_FField.hpp>

    public:
        /**
         * Returns the class of the field, depending on the UE version it would
         * be either FFieldClass* (on UE4.25+), or UClass* object
         * Regardless of the underlying type, you can retrieve the name using GetName
         * and check the class hierarchy using get_superclass and IsChildOf
         */
        auto GetClass() -> FFieldClassVariant;
        void SetClass(FField* NewClass);
        void SetClass(UClass* NewClass);

        /**
         * Returns name of this property, as FName instance
         */
        auto GetFName() -> FName;

        /**
        * Returns name of this property, as string
        */
        inline auto GetName() -> std::wstring
        {
            return GetFName().ToString();
        }

        File::StringType GetFullName();
        File::StringType GetPathName(UObject* StopOuter = nullptr);

        /**
         * Checks whenever this property is of the class specified by the argument
         */
        auto IsA(const FFieldClassVariant& UClass) -> bool;

        template<FFieldDerivative FFieldDerivedType>
        inline auto IsA() -> bool
        {
            return IsA(FFieldDerivedType::StaticClass());
        }

        /**
         * Returns the owner of this field
         * In versions below 4.25, it would always represent the object
         */
        auto GetOwnerVariant() -> FFieldVariant;
        void SetOwnerVariant(FField*);
        void SetOwnerVariant(UObject*);

        UObject* GetOutermostOwner();

        /**
         * Returns the first UObject owner of this field of the provided type
         */
        auto GetTypedOwner(UClass* OwnerType) -> UObject*;

        /**
         * Templated version of GetTypedOwner, will also cast the
         * returned object pointer automatically
         */
        template<UObjectDerivative T>
        inline auto GetTypedOwner() -> T*
        {
            return Cast<T>(GetTypedOwner(T::StaticClass()));
        }

        /**
         * Returns whether the 'Next' pointer is non-nullptr
         */
        bool HasNext();

        FProperty* GetNextFieldAsProperty();

    private:
        friend class UStruct;

        /**
         * Returns the next FField object in the linked list of class
         * properties defined by the UClass::ChildrenProperties
         * Will throw the exception if the UE version is below 4.25
         */
        auto GetNextFFieldUnsafe() -> FField*;

        /**
         * Converts this field to the underlying UField object
         * Conversion is only possible in UE versions below 4.25, so if this function
         * is called on newer UE versions it will throw exception
         */
        auto AsUFieldUnsafe() -> class UField*;
        auto AsUFieldUnsafe() const -> const class UField*;

        /**
         * Retrieves the underlying FFieldClass of this field if possible
         * Will throw the exception if UE version is below 4.25
         */
        auto GetFFieldClassUnsafe() -> FFieldClass*;

        /**
         * Returns the owner of the FField in the UE versions above 4.25
         * Will throw the exception if UE version is below 4.25
         */
        auto GetFFieldOwnerUnsafe() -> FFieldVariant;

        /**
        * Returns the name of the FField in the UE versions above 4.25
        * Will throw the exception if UE version is below 4.25
        */
        auto GetFFieldFNameUnsafe() -> FName;


        // Virtual Functions
    public:
        auto Serialize(FArchive& Ar) -> void;
        auto PostLoad() -> void;
        auto GetPreloadDependencies(TArray<UObject*>& OutDeps) -> void;
        auto BeginDestroy() -> void;
        using FReferenceCollector = void*; // Remove if/when we have an FArchive implementation, for now, probably a bad idea to call
        auto AddReferencedObjects(FReferenceCollector& Collector) -> void;
        auto AddCppProperty(class FProperty* Property) -> void;
        auto Bind() -> void;
        auto PostDuplicate(const FField& InField) -> void;
        auto GetInnerFieldByName(const FName& InName) -> FField*;
        auto GetInnerFields(TArray<FField*>& OutFields) -> void;

        // Compatibility with <4.25
        // Throws in 4.25+
        void PostDuplicate(bool bDuplicateForPIE);
        bool NeedsLoadForClient() const;
        bool NeedsLoadForServer() const;
    };

    /**
     * A union representing a FField object or an UObject
     * Used primarily to represent a FField object hierarchy, since FField owner can represent both
     */
    class RC_UE_API FFieldVariant
    {
        union FFieldObjectUnion
        {
            FField* Field;
            UObject* Object;
        } Container;
        bool IsObject;
    public:
        FFieldVariant(FField* Field) : IsObject(false)
        {
            Container.Field = Field;
        }

        FFieldVariant(UObject* Object) : IsObject(true)
        {
            Container.Object = Object;
        }
    public:
        auto IsValid() -> bool
        {
            return Container.Object;
        }

        auto GetOwnerVariant() -> FFieldVariant;

        auto IsUObject() -> bool
        {
            return IsObject;
        }

        auto ToField() -> FField*
        {
            if (!IsUObject())
            {
                return Container.Field;
            }
            else
            {
                return nullptr;
            }
        }

        auto ToUObject() -> UObject*
        {
            if (IsUObject())
            {
                return Container.Object;
            }
            else
            {
                return nullptr;
            }
        }

        void Set(FField*);
        void Set(UObject*);

        auto HashObject() -> size_t;
    };

    /**
     * Represents a FField class independently of the UE version
     * In the UE versions above 4.25 this would be a FFieldClass object,
     * but on earlier version it would be represented by the UClass
     *
     * Methods here allow working with FField classes in underlying type independent matter
     */
    class RC_UE_API FFieldClassVariant
    {
    private:
        union FFieldClassObjectUnion
        {
            FFieldClass* Field;
            const UClass* Object;
        } Container;
        bool IsObject;
    public:
        /**
         * Constructs the FFieldClassVariant from the provided FFieldClass object
         * @param Field a valid FFieldClass object
         */
        FFieldClassVariant(FFieldClass* Field);

        /**
         * Constructs the FFieldClassVariant from the provided UClass object
         * @param Object a valid UClass object
         */
        FFieldClassVariant(UClass* Object);
        FFieldClassVariant(const UClass* Object);

        /**
         * Constructs an invalid instance of the FFieldClassVariant representing a nullptr
         * The resulting instance cannot be de-referenced into neither of the types
         */
        FFieldClassVariant();
    public:
        /**
         * Checks whenever this variant represents a valid class and not a nullptr
         * @return true if this is a valid class
         */
        auto IsValid() const -> bool;

        /**
         * Retrieves the class name, independently of the underlying type
         */
        auto GetFName() const -> FName;

        /**
         * Retrieves the superclass of the class, independently of the underlying type
         */
        auto GetSuperClass() const -> FFieldClassVariant;

        /**
         * Determines whenever the property class is a children of the provided class
         * This will always return false when used to compare uclasses and field classes
         */
        auto IsChildOf(FFieldClassVariant UClass) const -> bool;

        /**
         * Retrieves the class name, independently of the underlying type
         */
        inline auto GetName() const -> std::wstring
        {
            return GetFName().ToString();
        }

        EClassCastFlags GetClassCastFlags() const;

        inline bool HasAnyCastFlags(const uint64 InCastFlags) const
        {
            return !!(GetClassCastFlags() & InCastFlags);
        }
        
        inline bool HasAllCastFlags(const uint64 InCastFlags) const
        {
            return (GetClassCastFlags() & InCastFlags) == InCastFlags;
        }

        void Set(FFieldClass*);
        void Set(UClass*);
        void Set(const UClass*);

        /** Equality operator for FFieldClassVariant, they are equal if they both point to the same class */
        auto operator==(const RC::Unreal::FFieldClassVariant& Rhs) const -> bool;

        /** Computes the hash of the object */
        auto HashObject() const -> size_t;
    private:
        friend class UStruct;
        friend class FField;

        auto IsUClass() const -> bool;
        auto IsFieldClass() const -> bool;

        auto ToFieldClass() const -> FFieldClass*;
        auto ToUClass() const -> const UClass*;
    };

    /**
    * Represents a FField clas in the UE versions above 4.25
    * Has a structure similar to the UClass
    */
    class RC_UE_API FFieldClass
    {
    public:
        FName Name;
        uint64_t Id;
        uint64_t CastFlags;
        EClassFlags ClassFlags;
        FFieldClass* SuperClass;
        FField* DefaultObject;
        FField* ConstructFn;
        //FThreadSafeCounter unique_name_index_counter;
    public:
        auto GetFName() const -> FName;

        auto GetSuperClass() const -> FFieldClass*;

        auto IsChildOf(FFieldClass* FieldClass) const -> bool;

        inline auto GetName() const -> std::wstring
        {
            return GetFName().ToString();
        }
    };

    /** Casts the field to the specified type after performing the type checking */
    template<FFieldDerivative T>
    inline auto CastField(FField* Field) -> T* {
        return Field != nullptr && Field->IsA<T>() ? static_cast<T*>(Field) : nullptr;
    }

    namespace Internal
    {
        /** Virtual function type accessor for FField objects */
        class FFieldTypeAccessor : public BaseTypeAccessor
        {
        private:
            static std::vector<void(*)()> LateBindCallbacks;
            static bool TypeSystemInitialized;
        public:
            using ClassType = FFieldClassVariant;

            template<typename T>
            inline static auto StaticClass() -> FFieldClassVariant
            {
                return T::StaticClass();
            }
            static auto GetObjectClass(FField* Field) -> FFieldClassVariant;
            static auto GetClassSuperClass(FFieldClassVariant FieldClass) -> FFieldClassVariant;
            static auto IsClassValid(FFieldClassVariant FieldClass) -> bool;
            static auto RegisterLateBindCallback(void(*Callback)()) -> void;
            static auto OnTypeSystemInitialized() -> void;
        };
    }
}

template<>
struct std::hash<RC::Unreal::FFieldClassVariant>
{
    std::size_t operator()(const RC::Unreal::FFieldClassVariant& S) const noexcept
    {
        return S.HashObject();
    }
};

#endif //RC_UNREAL_FFIELD_HPP
