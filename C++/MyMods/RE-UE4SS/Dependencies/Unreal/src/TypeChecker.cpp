#include <algorithm>

#include <DynamicOutput/DynamicOutput.hpp>
#include <Helpers/Casting.hpp>
#include <Unreal/TypeChecker.hpp>
#include <Unreal/UObject.hpp>
#include <Unreal/AActor.hpp>
#include <Unreal/FField.hpp>
#include <Unreal/UStruct.hpp>
#include <Unreal/UClass.hpp>
#include <Unreal/UFunction.hpp>
#include <Unreal/FProperty.hpp>
#include <Unreal/UScriptStruct.hpp>
#include <Unreal/UEnum.hpp>
#include <Unreal/FAssetData.hpp>
#include <Unreal/UInterface.hpp>
#include <Unreal/UActorComponent.hpp>
#include <Unreal/UGameViewportClient.hpp>
#include <Unreal/UPackage.hpp>
#include <Unreal/CanvasPanel.hpp>
#include <Unreal/World.hpp>
#include <Unreal/Property/FNumericProperty.hpp>
#include <Unreal/Property/NumericPropertyTypes.hpp>
#include <Unreal/Property/FObjectProperty.hpp>
#include <Unreal/Property/FWeakObjectProperty.hpp>
#include <Unreal/Property/FLazyObjectProperty.hpp>
#include <Unreal/Property/FSoftObjectProperty.hpp>
#include <Unreal/Property/FClassProperty.hpp>
#include <Unreal/Property/FSoftClassProperty.hpp>
#include <Unreal/Property/FArrayProperty.hpp>
#include <Unreal/Property/FMapProperty.hpp>
#include <Unreal/Property/FBoolProperty.hpp>
#include <Unreal/Property/FNameProperty.hpp>
#include <Unreal/Property/FStructProperty.hpp>
#include <Unreal/Property/FEnumProperty.hpp>
#include <Unreal/Property/FTextProperty.hpp>
#include <Unreal/Property/FStrProperty.hpp>
#include <Unreal/Property/FDelegateProperty.hpp>
#include <Unreal/Property/FMulticastInlineDelegateProperty.hpp>
#include <Unreal/Property/FMulticastSparseDelegateProperty.hpp>
#include <Unreal/Property/FInterfaceProperty.hpp>
#include <Unreal/Property/FFieldPathProperty.hpp>
#include <Unreal/Property/FSetProperty.hpp>
#include <Unreal/UnrealVersion.hpp>

namespace RC::Unreal
{
    FName GWorldName{};
    FName GLevelName{};
    FName GPackageName{};
    FName GPropertyName{};
    FName GFunctionName{};

    auto TypeChecker::get_world_name() -> FName
    {
        return GWorldName;
    }

    auto TypeChecker::get_level_name() -> FName
    {
        return GLevelName;
    }

    auto TypeChecker::store_all_object_names() -> void
    {
        //@formatter:off
        // Misc
        GWorldName    = FName(L"World");
        GLevelName    = FName(L"Level");
        GPackageName  = FName(L"Package");
        GPropertyName = FName(L"Property");
        GFunctionName = FName(L"Function");
        //@formatter:on
    }

    auto TypeChecker::store_all_object_types() -> bool
    {
        UObject::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.Object");
        UField::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.Field");
        UStruct::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.Struct");
        AActor::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/Engine.Actor");
        UWorld::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/Engine.World");

        UClass* enum_ptr = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.Enum");
        UEnum::StaticClassStorage = enum_ptr;

        UClass* user_defined_enum_ptr = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/Engine.UserDefinedEnum");
        UUserDefinedEnum::StaticClassStorage = user_defined_enum_ptr;

        UClass* class_ptr = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.Class");
        UClass::StaticClassStorage = class_ptr;

        UClass* bp_generated_class_ptr = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/Engine.BlueprintGeneratedClass");
        UBlueprintGeneratedClass::StaticClassStorage = bp_generated_class_ptr;

        UClass* widget_bp_generated_class_ptr = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/UMG.WidgetBlueprintGeneratedClass");
        UWidgetBlueprintGeneratedClass::StaticClassStorage = widget_bp_generated_class_ptr;

        UClass* anim_bp_generated_class_ptr = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/Engine.AnimBlueprintGeneratedClass");
        UAnimBlueprintGeneratedClass::StaticClassStorage = anim_bp_generated_class_ptr;

        UClass* canvas_panel_ptr = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/UMG.CanvasPanel");
        UCanvasPanel::StaticClassStorage = canvas_panel_ptr;

        // Not available in 4.12 (I've not checked exactly when it starts being available)
        UClass* asset_data_ptr = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, STR("/Script/AssetRegistry.AssetData"));
        if (!asset_data_ptr)
        {
            // In 4.26, they moved it from the 'AssetRegistry' package to the 'CoreUObject' package
            asset_data_ptr = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, STR("/Script/CoreUObject.AssetData"));
        }
        FAssetData::StaticClassStorage = asset_data_ptr;

        UPackage::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.Package");
        UInterface::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.Interface");
        UActorComponent::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/Engine.ActorComponent");
        USceneComponent::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/Engine.SceneComponent");
        UGameViewportClient::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/Engine.GameViewportClient");

        UFunction::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, STR("/Script/CoreUObject.Function"));
        //UDelegateFunction::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, STR("/Script/CoreUObject.DelegateFunction"));

        if (Version::IsAtLeast(4, 23))
        {
            //USparseDelegateFunction::StaticClassStorage = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, STR("/Script/CoreUObject.SparseDelegateFunction"));
        }

        UClass* script_struct_ptr = UObjectGlobals::StaticFindObject<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.ScriptStruct");
        UScriptStruct::StaticClassStorage = script_struct_ptr;

        /*
        FProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.Property");
        FNumericProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.NumericProperty");
        FInt8Property::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.Int8Property");
        FInt16Property::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.Int16Property");
        FIntProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.IntProperty");
        FInt64Property::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.Int64Property");
        FFloatProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.FloatProperty");
        FDoubleProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.DoubleProperty");
        FByteProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.ByteProperty");
        FUInt16Property::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.UInt16Property");
        FUInt32Property::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.UInt32Property");
        FUInt64Property::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.UInt64Property");
        FObjectProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.ObjectProperty");
        FClassProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.ClassProperty");
        FSoftClassProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.SoftClassProperty");
        FEnumProperty<uint8_t>::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.EnumProperty");
        FArrayProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.ArrayProperty");
        FStructProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.StructProperty");
        FNameProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.NameProperty");
        XBoolProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.BoolProperty");
        FMapProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.MapProperty");
        FWeakObjectProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.WeakObjectProperty");
        FLazyObjectProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.LazyObjectProperty");
        FSoftObjectProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.SoftObjectProperty");
        FTextProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.TextProperty");
        FStrProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.StrProperty");
        FInterfaceProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.InterfaceProperty");
        FFieldPathProperty::m_static_obj = UObjectGlobals::static_find_object<UClass*>(nullptr, nullptr, L"/Script/CoreUObject.FieldPathProperty");
        //*/

        // FField / FProperty Types
        if (Version::IsAtLeast(4, 25))
        {
            auto find_all_property_types = [](const std::wstring& obj_string) -> void {
                UClass* actor_obj = static_cast<UClass*>(UObjectGlobals::StaticFindObject_InternalSlow(nullptr, nullptr, obj_string.c_str()));
                if (!actor_obj) { return; }

                // Manually iterating fields here because 'ForEachProperty' isn't ready until after this function is done
                FField* field = actor_obj->GetChildProperties();
                while (field)
                {
                    // Hard-coded offset cast here because 'FField::GetClass' is not ready until after this function is done
                    FFieldClass* ffield_class = Helper::Casting::ptr_cast_deref<FFieldClass*>(field, FFieldClassOffset);
                    if (!ffield_class)
                    {
                        field = field->GetNextFFieldUnsafe();
                        continue;
                    }

                    FName type_name = ffield_class->GetFName();

                    // TODO: Look at the dumped objects and put every single FField type in here
                    // At the moment there are probably some missing types

                    // Fully supported
                    if (type_name == FName(L"ObjectProperty"))
                    {
                        if ((ffield_class->CastFlags & EClassCastFlags::CASTCLASS_FObjectPtrProperty) != 0)
                        {
                            FObjectPtrProperty::StaticClassStorage = ffield_class;
                        }
                        else
                        {
                            FObjectProperty::StaticClassStorage = ffield_class;
                        }
                    }
                    if (type_name == FName(L"ObjectPtrProperty"))
                    {
                        // I don't think this is ever hit anymore, but I'm not entirely sure.
                        // It seems that FObjectPtrProperty uses the 'ObjectProperty FName in the final UE5.0 release.
                        FObjectPtrProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"Int8Property"))
                    {
                        FInt8Property::StaticClassStorage = ffield_class;

                        // This doesn't need to be in 'Int8Property', it can be in any property
                        FFieldClass* ffield_super_class = ffield_class->GetSuperClass();
                        if (ffield_super_class)
                        {
                            do
                            {
                                FName super_type_name = ffield_super_class->GetFName();
                                if (super_type_name == GPropertyName)
                                {
                                    FProperty::StaticClassStorage = ffield_super_class;
                                    break;
                                }

                                ffield_super_class = ffield_super_class->GetSuperClass();
                            } while (ffield_super_class);
                        }
                    }
                    if (type_name == FName(L"Int16Property"))
                    {
                        FInt16Property::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"IntProperty"))
                    {
                        FIntProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"Int64Property"))
                    {
                        FInt64Property::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"NameProperty"))
                    {
                        FNameProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"FloatProperty"))
                    {
                        FFloatProperty::StaticClassStorage = static_cast<FFieldClass*>(ffield_class);

                        // 'NumericProperty' doesn't appear as the direct type for any properties
                        // Because of this, we need to use a property that we know has 'NumericProperty' in its super chain
                        // We're using 'FFloatProperty' here for no particular reason other than that it has 'NumericProperty' as it's super
                        FNumericProperty::StaticClassStorage = ffield_class->SuperClass;
                    }
                    if (type_name == FName(L"DoubleProperty"))
                    {
                        FDoubleProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"ByteProperty"))
                    {
                        FByteProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"UInt16Property"))
                    {
                        FUInt16Property::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"UInt32Property"))
                    {
                        FUInt32Property::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"UInt64Property"))
                    {
                        FUInt64Property::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"BoolProperty"))
                    {
                        FBoolProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"ArrayProperty"))
                    {
                        FArrayProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"MapProperty"))
                    {
                        FMapProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"StructProperty"))
                    {
                        FStructProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"ClassProperty"))
                    {
                        FClassProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"ClassPtrProperty"))
                    {
                        FClassPtrProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"SoftClassProperty"))
                    {
                        FSoftClassProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"WeakObjectProperty"))
                    {
                        FWeakObjectProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"LazyObjectProperty"))
                    {
                        FLazyObjectProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"SoftObjectProperty"))
                    {
                        FSoftObjectProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"EnumProperty"))
                    {
                        FEnumProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"TextProperty"))
                    {
                        FTextProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"StrProperty"))
                    {
                        FStrProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"DelegateProperty"))
                    {
                        FDelegateProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"MulticastInlineDelegateProperty"))
                    {
                        FMulticastInlineDelegateProperty::StaticClassStorage = ffield_class;
                        FMulticastDelegateProperty::StaticClassStorage = ffield_class->GetSuperClass();

                        // Attempt to get the pointer to the FObjectProperty FFieldClass.
                        // It seems that all UObject parameters are of type FObjectProperty and not FObjectPtrProperty.
                        // This doesn't have to go in the delegate property section, it can also go in the UFunction section.
                        // The 'HashObject' function simply returns the address in a size_t, but keep this in mind if the 'HashObject' function ever changes.
                        if (Version::IsAtLeast(5, 0) && std::bit_cast<void*>(FObjectProperty::StaticClassStorage.HashObject()) == STATIC_CLASS_INVALID)
                        {
                            FMulticastInlineDelegateProperty* AsMulticastInlineDelegateProperty = static_cast<FMulticastInlineDelegateProperty*>(field);
                            for (FProperty* Param : AsMulticastInlineDelegateProperty->GetSignatureFunction()->ForEachProperty()) 
                            {
                                if (Param->GetClass().GetName() == STR("ObjectProperty"))
                                {
                                    FObjectProperty::StaticClassStorage = Param->GetClass();
                                    break;
                                }
                            }
                        }
                    }
                    if (type_name == FName(L"MulticastSparseDelegateProperty"))
                    {
                        FMulticastSparseDelegateProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"InterfaceProperty"))
                    {
                        FInterfaceProperty::StaticClassStorage = ffield_class;
                    }
                    if (type_name == FName(L"FieldPathProperty"))
                    {
                        FFieldPathProperty::StaticClassStorage = ffield_class;
                    }

                    field = field->GetNextFFieldUnsafe();
                }
            };

            // TODO: Maybe replace all of the calls to 'find_all_property_types' with a GUObjectArray iteration with an early exit once everything's been found ?

            // Bool, Enum, Byte, Struct, Float, Object, Name, Int, Array
            // WeakObject, MulticastSparseDelegate
            find_all_property_types(L"/Script/Engine.Actor");
            // Class
            find_all_property_types(L"/Script/Engine.Pawn");
            // Str, Map
            find_all_property_types(L"/Script/Engine.NetDriver");
            // Double
            find_all_property_types(L"/Script/Engine.NetConnection");
            // Text
            find_all_property_types(L"/Script/Engine.GameModeBase");
            // Int8, LazyObject
            find_all_property_types(L"/Script/Landscape.LandscapeComponent");
            // UInt16, UInt32, UInt64, Int8, Int16, Int64
            find_all_property_types(L"/Script/Engine.IntSerialization");
            // Set, MulticastInlineDelegate, Delegate
            find_all_property_types(L"/Script/Engine.AudioComponent");
            // MulticastInlineDelegate, Interface
            find_all_property_types(L"/Script/MovieScene.MovieSceneSequencePlayer");
            // Delegate
            find_all_property_types(L"/Script/UMG.Widget");
            // SoftObject
            find_all_property_types(L"/Script/Engine.LevelStreaming");
            // SoftClass
            find_all_property_types(L"/Script/Engine.PrimaryAssetTypeInfo");
            // FieldPath
            find_all_property_types(L"/Script/Engine.InterpTrackInstProperty");
        }
        else
        {
            // 4.24 and earlier, just use StaticFindObject to find all of the property type pointers

            auto add_property = []<typename PropertyType>(const wchar_t* full_property_name, [[maybe_unused]]PropertyType property_type_object) {
                UObject* property = UObjectGlobals::StaticFindObject_InternalSlow(nullptr, nullptr, full_property_name);
                if (!property)
                {
                    // TODO: Put this error back when you've confirmed when every property type was introduced and you're only trying to find it in those versions and later
                    /*
                    std::wstring error = std::format(L"Was unable to find pointer to '{}'", full_property_name);
                    std::string error_ansi = std::string(error.begin(), error.end());
                    throw std::runtime_error{error_ansi};
                    //*/
                    return;
                }

                if constexpr (!std::is_same_v<PropertyType, int32_t>)
                {
                    PropertyType::StaticClassStorage = static_cast<UClass*>(property);
                }
            };

            add_property(L"/Script/CoreUObject.ObjectProperty", FObjectProperty{});
            // AssetObjectProperty & AssetClassProperty only exists in <4.18.
            add_property(L"/Script/CoreUObject.AssetObjectProperty", FAssetObjectProperty{});
            add_property(L"/Script/CoreUObject.AssetClassProperty", FAssetClassProperty{});
            add_property(L"/Script/CoreUObject.NumericProperty", FNumericProperty{});
            add_property(L"/Script/CoreUObject.Int8Property", FInt8Property{});
            add_property(L"/Script/CoreUObject.Int16Property", FInt16Property{});
            add_property(L"/Script/CoreUObject.IntProperty", FIntProperty{});
            add_property(L"/Script/CoreUObject.Int64Property", FInt64Property{});
            add_property(L"/Script/CoreUObject.NameProperty", FNameProperty{});
            add_property(L"/Script/CoreUObject.FloatProperty", FFloatProperty{});
            add_property(L"/Script/CoreUObject.DoubleProperty", FDoubleProperty{});
            add_property(L"/Script/CoreUObject.ByteProperty", FByteProperty{});
            add_property(L"/Script/CoreUObject.UInt16Property", FUInt16Property{});
            add_property(L"/Script/CoreUObject.UInt32Property", FUInt32Property{});
            add_property(L"/Script/CoreUObject.UInt64Property", FUInt64Property{});
            add_property(L"/Script/CoreUObject.BoolProperty", FBoolProperty{});
            add_property(L"/Script/CoreUObject.ArrayProperty", FArrayProperty{});
            add_property(L"/Script/CoreUObject.MapProperty", FMapProperty{});
            add_property(L"/Script/CoreUObject.StructProperty", FStructProperty{});
            add_property(L"/Script/CoreUObject.ClassProperty", FClassProperty{});
            add_property(L"/Script/CoreUObject.SoftClassProperty", FSoftClassProperty{});
            add_property(L"/Script/CoreUObject.WeakObjectProperty", FWeakObjectProperty{});
            add_property(L"/Script/CoreUObject.LazyObjectProperty", FLazyObjectProperty{});
            add_property(L"/Script/CoreUObject.SoftObjectProperty", FSoftObjectProperty{});
            if (Version::IsAtLeast(4, 15)) { add_property(L"/Script/CoreUObject.EnumProperty", FEnumProperty{}); }
            add_property(L"/Script/CoreUObject.TextProperty", FTextProperty{});
            add_property(L"/Script/CoreUObject.StrProperty", FStrProperty{});
            add_property(L"/Script/CoreUObject.DelegateProperty", FDelegateProperty{});
            add_property(L"/Script/CoreUObject.MulticastDelegateProperty", FMulticastDelegateProperty{});
            if (Version::IsAtLeast(4, 23)) { add_property(L"/Script/CoreUObject.MulticastInlineDelegateProperty", FMulticastInlineDelegateProperty{}); }
            if (Version::IsAtLeast(4, 23)) { add_property(L"/Script/CoreUObject.MulticastSparseDelegateProperty", FMulticastSparseDelegateProperty{}); }
            add_property(L"/Script/CoreUObject.InterfaceProperty", FInterfaceProperty{});

            // Not yet supported, only here for completion and to prevent crashes
            // Not all of these will be found right now, need to call this function with more UObjects that actually have these properties
            add_property(L"/Script/CoreUObject.SetProperty", FSetProperty{});

            // Find the root 'Property' FField. This may not be necessary but I'm leaving it here for now, might be useful later.
            add_property(L"/Script/CoreUObject.Property", FProperty{});
        }

        return true;
    }

    auto TypeChecker::is_property(FField* field) -> bool
    {
        UObject* object = std::bit_cast<UObject*>(field);
        return is_property(object);
    }

    auto TypeChecker::is_property(UObject* object) -> bool
    {
        UClass* obj_class = object->GetClassPrivate();
        if (!obj_class) { return false; }

        if (obj_class->GetNamePrivate() == GPropertyName) { return true; }

        UStruct* super_struct = obj_class->GetSuperStruct();
        while (super_struct)
        {
            if (super_struct->GetNamePrivate() == GPropertyName)
            {
                return true;
            }

            super_struct = super_struct->GetSuperStruct();
        }

        return false;
    }
}