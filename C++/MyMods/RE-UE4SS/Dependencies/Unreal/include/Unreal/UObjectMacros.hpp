#ifndef RC_UNREAL_UOBJECTMACROS_HPP
#define RC_UNREAL_UOBJECTMACROS_HPP

#include <Unreal/PrimitiveTypes.hpp>

#pragma warning(disable: 4068)
#pragma clang diagnostic ignored "-Wstring-plus-int"
#pragma warning(default: 4068)

namespace RC::Unreal {
    class UClass;
    class FFieldClassVariant;

    using ERenameFlags = uint32;
}

/** Default rename behavior */
#define REN_None				(0x0000)
/** Rename won't call ResetLoaders or flush async loading. You should pass this if you are renaming a deep subobject and do not need to reset loading for the outer package */
#define REN_ForceNoResetLoaders		(0x0001)
/** Just test to make sure that the rename is guaranteed to succeed if an non test rename immediately follows */
#define REN_Test					(0x0002)
/** Indicates that the object (and new outer) should not be dirtied */
#define REN_DoNotDirty				(0x0004)
/** Don't create an object redirector, even if the class is marked RF_Public */
#define REN_DontCreateRedirectors	(0x0010)
/** Don't call Modify() on the objects, so they won't be stored in the transaction buffer */
#define REN_NonTransactional		(0x0020)
/** Force unique names across all packages not just within the scope of the new outer */
#define REN_ForceGlobalUnique		(0x0040)
/** Prevent renaming of any child generated classes and CDO's in blueprints */
#define REN_SkipGeneratedClasses	(0x0080)

// Value holding the meaning for when a StaticClass doesn't exist in this engine version.
// T::StaticClass() will return false instead of throw if 'StaticClassStorage' is set to this value.
// The 'TypeChecker' system will set 'StaticClassStorage' to the correct pointer if one exists, or nullptr if one doesn't exist.
static inline RC::Unreal::UClass* STATIC_CLASS_INVALID = reinterpret_cast<RC::Unreal::UClass* const>(-2);

#define DECLARE_EXTERNAL_OBJECT_CLASS(ClassName, ModuleName) \
private: \
    static RC::Unreal::UClass* StaticClassStorage; \
    template<typename T>\
    friend class RC::Unreal::Internal::UClassRegistrarTemplate; \
    friend class RC::Unreal::TypeChecker; \
\
    inline static RC::Unreal::UClass** StaticClassPtr() { return &ClassName::StaticClassStorage; } \
    inline static const wchar_t* StaticPackage() { return STR("/Script/") STR(#ModuleName); }   \
    inline static const wchar_t* StaticClassName() { return (STR(#ClassName) + 1); } \
public: \
    auto static StaticClass() -> RC::Unreal::UClass*; \

#define IMPLEMENT_EXTERNAL_OBJECT_CLASS(ClassName) \
RC::Unreal::UClass* ClassName::StaticClassStorage = STATIC_CLASS_INVALID; \
static RC::Unreal::Internal::UClassRegistrarTemplate<ClassName> __class_registrar_##ClassName;\
\
auto ClassName::StaticClass() -> RC::Unreal::UClass* \
{ \
    if (!StaticClassStorage) \
    { \
        throw std::runtime_error{"[" #ClassName "::StaticClass] StaticClassStorage is nullptr"}; \
    } \
    else if (StaticClassStorage == STATIC_CLASS_INVALID) \
    { \
        return nullptr; \
    } \
    return StaticClassStorage; \
};

#define DECLARE_FIELD_CLASS(ClassName) \
private: \
    static RC::Unreal::FFieldClassVariant StaticClassStorage; \
    template<typename T>\
    friend class RC::Unreal::Internal::FFieldClassRegistrarTemplate; \
    friend class RC::Unreal::TypeChecker; \
\
    inline static RC::Unreal::FFieldClassVariant* StaticClassPtr() { return &ClassName::StaticClassStorage; } \
    inline static const wchar_t* StaticClassName() { return (STR(#ClassName) + 1); } \
public: \
    auto static StaticClass() -> RC::Unreal::FFieldClassVariant;    \

#define IMPLEMENT_FIELD_CLASS(ClassName) \
RC::Unreal::FFieldClassVariant ClassName::StaticClassStorage{(RC::Unreal::FFieldClass*) STATIC_CLASS_INVALID}; \
static RC::Unreal::Internal::FFieldClassRegistrarTemplate<ClassName> __field_class_registrar_##ClassName;\
\
auto ClassName::StaticClass() -> RC::Unreal::FFieldClassVariant \
{ \
    if (!StaticClassStorage.IsValid()) \
    { \
        throw std::runtime_error{"[" #ClassName "::StaticClass] StaticClassStorage is not valid"}; \
    } \
    else if (StaticClassStorage == STATIC_CLASS_INVALID) \
    { \
        return {}; \
    }\
    return StaticClassStorage; \
};

namespace RC::Unreal::Internal
{
    class RC_UE_API UClassRegistrar
    {
    protected:
        UClassRegistrar(RC::Unreal::UClass** OutStaticClass, const wchar_t* ClassName, const wchar_t* PackageName)
        {
            (void)OutStaticClass;
            (void)ClassName;
            (void)PackageName;
        };
    };

    class RC_UE_API FFieldClassRegistrar
    {
    protected:
        FFieldClassRegistrar(RC::Unreal::FFieldClassVariant* OutStaticClass, const wchar_t* ClassName)
        {
            (void)OutStaticClass;
            (void)ClassName;
        }
    };

    template<typename T>
    class UClassRegistrarTemplate : public UClassRegistrar
    {
    public:
        inline UClassRegistrarTemplate() : UClassRegistrar(T::StaticClassPtr(), T::StaticClassName(), T::StaticPackage()) {
        }
    };

    template<typename T>
    class FFieldClassRegistrarTemplate : public FFieldClassRegistrar
    {
    public:
        inline FFieldClassRegistrarTemplate() : FFieldClassRegistrar(T::StaticClassPtr(), T::StaticClassName()) {
        }
    };
}

#endif //RC_UNREAL_UOBJECTMACROS_HPP
