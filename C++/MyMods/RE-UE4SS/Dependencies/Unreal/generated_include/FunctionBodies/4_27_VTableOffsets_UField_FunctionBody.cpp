if (auto it = UField::VTableLayoutMap.find(STR("__vecDelDtor_4")); it == UField::VTableLayoutMap.end())
{
    UField::VTableLayoutMap.emplace(STR("__vecDelDtor_4"), 0x0);
}

if (auto it = UField::VTableLayoutMap.find(STR("AddCppProperty")); it == UField::VTableLayoutMap.end())
{
    UField::VTableLayoutMap.emplace(STR("AddCppProperty"), 0x270);
}

if (auto it = UField::VTableLayoutMap.find(STR("Bind")); it == UField::VTableLayoutMap.end())
{
    UField::VTableLayoutMap.emplace(STR("Bind"), 0x278);
}

