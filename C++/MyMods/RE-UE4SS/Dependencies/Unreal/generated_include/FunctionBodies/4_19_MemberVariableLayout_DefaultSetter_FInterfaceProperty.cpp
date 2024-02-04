if (auto it = FInterfaceProperty::MemberOffsets.find(STR("InterfaceClass")); it == FInterfaceProperty::MemberOffsets.end())
{
    FInterfaceProperty::MemberOffsets.emplace(STR("InterfaceClass"), 0x70);
}

