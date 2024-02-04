#include <Unreal/UEnum.hpp>
#include <Unreal/UClass.hpp>
#include <Helpers/Casting.hpp>

namespace RC::Unreal
{
    IMPLEMENT_EXTERNAL_OBJECT_CLASS(UEnum);
    IMPLEMENT_EXTERNAL_OBJECT_CLASS(UUserDefinedEnum);

#include <MemberVariableLayout_SrcWrapper_UEnum.hpp>

    TArray<TPair<FName, uint8>>& UEnum::GetEnumNamesOldUnsafe()
    {
        static auto Offset = MemberOffsets.find(STR("Names"));
        if (Offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::Names' (for GetNameByValue) that doesn't exist in this engine version."}; }
        return *Helper::Casting::ptr_cast<TArray<TPair<FName, uint8>>*>(this, Offset->second);
    }

    TArray<TPair<FName, int64>>& UEnum::GetEnumNamesNewUnsafe()
    {
        static auto Offset = MemberOffsets.find(STR("Names"));
        if (Offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::Names' (for GetNameByValue) that doesn't exist in this engine version."}; }
        return *Helper::Casting::ptr_cast<TArray<TPair<FName, int64>>*>(this, Offset->second);
    }

    auto UEnum::GetEnumNames() -> FEnumNameArray&
    {
        if (Version::IsBelow(4, 15))
        {
            throw std::runtime_error{"UEnum::GetEnumNames/GetNames is not safe for <4.15 because the names array type changed and we haven't abstracted that yet"};
        }
        else
        {
            return GetNames();
        }
    }

    auto UEnum::GetEnumNameByIndex(size_t index) -> TTuple<FName, int64>
    {
        if (Version::IsBelow(4, 15))
        {
            auto* NameTuple = GetEnumNamesOldUnsafe().At(index);
            if (!NameTuple) { return {}; }
            return {NameTuple->Key, static_cast<int64_t>(NameTuple->Value)};
        }
        else
        {
            auto* NameTuple = GetEnumNamesNewUnsafe().At(index);
            if (!NameTuple) { return {}; }
            return *NameTuple;
        }
    }

    void UEnum::GetEnumNamesAsVector(std::vector<std::pair<FName, int64>>& OutNames)
    {
        if (Version::IsBelow(4, 15))
        {
            static auto Offset = MemberOffsets.find(STR("Names"));
            if (Offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::Names' (for GetNameByValue) that doesn't exist in this engine version."}; }
            auto Names = *Helper::Casting::ptr_cast<TArray<TPair<FName, uint8>>*>(this, Offset->second);
            for (TPair<FName, uint8>& Elem : Names) 
            {
                OutNames.emplace_back(std::pair{Elem.Key, Elem.Value});
            }
        }
        else
        {
            static auto Offset = MemberOffsets.find(STR("Names"));
            if (Offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::Names' (for GetNameByValue) that doesn't exist in this engine version."}; }
            auto Names = *Helper::Casting::ptr_cast<TArray<TPair<FName, int64>>*>(this, Offset->second);

            for (TPair<FName, int64>& Elem : Names)
            {
                OutNames.emplace_back(std::pair{Elem.Key, Elem.Value});
            }
        }
    }

    auto UEnum::GetEnumFlags() -> EEnumFlags
    {
        if (Version::IsBelow(4, 26))
        {
            // EEnumFlags was added in 4.26
            // Let's assume the 'None' flag is valid for whatever code calls this function in <4.26
            return EEnumFlags::None;
        }
        else
        {
            // The offset of 'Names' + the size of 'Names' + the size of 'CppForm' = offset of 'EnumFlags'
            return GetEnumFlags_Internal();
        }
    }

    FName UEnum::GetNameByValue(int64_t Value)
    {
        FName ReturnValue{};

        if (Version::IsBelow(4, 15))
        {
            static auto Offset = MemberOffsets.find(STR("Names"));
            if (Offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::Names' (for GetNameByValue) that doesn't exist in this engine version."}; }
            auto Names = *Helper::Casting::ptr_cast<TArray<TPair<FName, uint8>>*>(this, Offset->second);

            for (TPair<FName, uint8>& Elem : Names) 
            {
                if (Elem.Value == Value)
                {
                    return Elem.Key;
                }
            }
        }
        else
        {
            static auto Offset = MemberOffsets.find(STR("Names"));
            if (Offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'UEnum::Names' (for GetNameByValue) that doesn't exist in this engine version."}; }
            auto Names = *Helper::Casting::ptr_cast<TArray<TPair<FName, int64>>*>(this, Offset->second);

            for (TPair<FName, int64>& Elem : Names) 
            {
                if (Elem.Value == Value)
                {
                    return Elem.Key;
                }
            }
        }

        return ReturnValue;
    }

    int32 UEnum::NumEnums()
    {
        if (Version::IsBelow(4, 15))
        {
            return GetEnumNamesOldUnsafe().Num();
        }
        else
        {
            return GetEnumNamesNewUnsafe().Num();
        }
    }

    StringType UEnum::GenerateEnumPrefix()
    {
        StringType enum_prefix;

        if (NumEnums() > 0)
        {
            enum_prefix = GetEnumNameByIndex(0).Key.ToString();
            
            // For each item in the enumeration, trim the prefix as much as necessary to keep it a prefix.
            // This ensures that once all items have been processed, a common prefix will have been constructed.
            // This will be the longest common prefix since as little as possible is trimmed at each step.
            for (auto [Name, Value] : ForEachName())
            {
                StringType EnumItemName = Name.ToString();

                // Find the length of the longest common prefix of Prefix and EnumItemName.
                int32 PrefixIdx = 0;
                while (PrefixIdx < enum_prefix.length() && PrefixIdx < EnumItemName.length() && enum_prefix[PrefixIdx] == EnumItemName[PrefixIdx])
                {
                    PrefixIdx++;
                }

                // Trim the prefix to the length of the common prefix.
                enum_prefix.resize(PrefixIdx);
            }

            // Find the index of the rightmost underscore in the prefix.
            int32 UnderscoreIdx = enum_prefix.find_last_of(STR("_"));

            // If an underscore was found, trim the prefix so only the part before the rightmost underscore is included.
            if (UnderscoreIdx > 0)
            {
                enum_prefix.resize(UnderscoreIdx);
            }
            else
            {
                // no underscores in the common prefix - this probably indicates that the names
                // for this enum are not using Epic's notation, so just empty the prefix so that
                // the max item will use the full name of the enum
                enum_prefix.clear();
            }
        }
        
        // If no common prefix was found, or if the enum does not contain any entries,
        // use the name of the enumeration instead.
        if (enum_prefix.length() == 0)
        {
            enum_prefix = GetName();
        }
        return enum_prefix;
    }


    
}
