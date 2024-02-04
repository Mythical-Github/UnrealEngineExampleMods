#ifndef RC_UNREAL_UFIELD_HPP
#define RC_UNREAL_UFIELD_HPP

#include <Unreal/UObject.hpp>

namespace RC::Unreal
{
    class RC_UE_API UField : public UObject
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(UField, CoreUObject);

        friend class FField;

    public:
        static std::unordered_map<File::StringType, uint32_t> VTableLayoutMap;

    public:
#include <MemberVariableLayout_HeaderWrapper_UField.hpp>

    protected:
        friend class UStruct;

        /**
         * Returns the next UField in a linked list defined by the UClass::Children property
         * Keep in mind that in UE versions below 4.25 it will also include UProperty objects!
         * Only for internal use, if you want to iterate properties or functions use for_each_property/function
         */
        [[deprecated("Use 'GetNext' instead")]]
        auto GetNextField() -> UField*;

        /**
         * Attempts to convert this UField to the FField object instance
         * The conversion is only possible for UE versions below 4.25, after 4.25 the
         * UField and FField have been separated
         * This function will throw the exception if the UE version is above 4.25
         */
        auto AsFFieldUnsafe() -> class FField*;

        // Virtual Functions
    public:
        void AddCppProperty(FProperty* Property);
        void Bind();
    };
}

#endif //RC_UNREAL_UFIELD_HPP
