#ifndef RC_UNREAL_UENUM_HPP
#define RC_UNREAL_UENUM_HPP

#include <format>
#include <vector>

#include <Constructs/Generator.hpp>
#include <Unreal/Common.hpp>
#include <Unreal/FField.hpp>
#include <Unreal/TypeChecker.hpp>
#include <Unreal/UField.hpp>
#include <Unreal/TArray.hpp>
#include <Unreal/TPair.hpp>
#include <Unreal/FText.hpp>
#include <Unreal/UnrealFlags.hpp>

namespace RC::Unreal
{
    // The "UEnum::Names" pair is "TPair<FName, uint8>" in earlier engine versions
    // This can cause a problem, therefore, you should be careful when using this pair
    // This is a case where we perhaps should abstract this array and deny direct access to the TArray
    using FEnumNamePair = TPair<FName, int64_t>;
    using FEnumNameArray = TArray<FEnumNamePair>;

    class RC_UE_API UEnum : public UField
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(UEnum, CoreUObject)

    public:
        enum class ECppForm
        {
            /**
             * Regular enums are declared using the normal enum keyword
             * Their constants are unscoped and usually prefixed with enum name
             */
            Regular,
            /**
             * Namespaced enums use the namespace for enum name + enum keyword for type
             * They are scoped to their namespace
             */
            Namespaced,
            /**
             * Enum classes are C++11 enum class enumerations that are properly scoped
             * They can also specify any integral underlying type
             */
            EnumClass
        };

    public:
#include <MemberVariableLayout_HeaderWrapper_UEnum.hpp>

    private:
        TArray<TPair<FName, uint8>>& GetEnumNamesOldUnsafe();
        TArray<TPair<FName, int64>>& GetEnumNamesNewUnsafe();

    public:
        /**
         * Returns the array of enumeration constants and their values
         * Keep in mind that enumeration can have gaps as well as negative values
         * The last entry of the array will always be a _MAX constant
         */
        auto GetEnumNames() -> FEnumNameArray&;
        auto GetEnumNameByIndex(size_t) -> TTuple<FName, int64>;
        void GetEnumNamesAsVector(std::vector<std::pair<FName, int64>>& OutNames);

        /**
         * Returns the flags set on the enumeration object
         * Will return EEnumFlags::None on older UE versions
         */
        auto GetEnumFlags() -> EEnumFlags;

        auto ForEachName() -> Generator<TPair<FName, int64>>
        {
            if (Version::IsBelow(4, 15))
            {
                for (TPair<FName, uint8>& Elem : GetEnumNamesOldUnsafe()) {
                    co_yield TPair<FName, int64>{Elem.Key, Elem.Value};
                }
            }
            else
            {
                for (TPair<FName, int64>& Elem : GetEnumNamesNewUnsafe()) {
                    co_yield Elem;
                }
            }
        }

        FName GetNameByValue(int64_t Value);

        /**
        * @return   The number of enum names.
        */
        int32 NumEnums();

        /**
        * Find the longest common prefix of all items in the enumeration.
        * 
        * @return   the longest common prefix between all items in the enum.  If a common prefix
        *           cannot be found, returns the full name of the enum.
        */
        StringType GenerateEnumPrefix();

        /**
         * Retrieves the enumeration index associated with the provided enum name
         * Returns INDEX_NONE if there is no enumeration constant with the provided name
         */
        //auto GetIndexByName(const std::wstring& name) -> int32_t;

        //auto GetValueByName(const std::wstring& name) -> int64_t;
    };

    class RC_UE_API UUserDefinedEnum : public UEnum
    {
        DECLARE_EXTERNAL_OBJECT_CLASS(UUserDefinedEnum, Engine);
    };
}


#endif //RC_UNREAL_UENUM_HPP
