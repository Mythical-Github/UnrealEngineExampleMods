if (auto it = FExec::VTableLayoutMap.find(STR("__vecDelDtor")); it == FExec::VTableLayoutMap.end())
{
    FExec::VTableLayoutMap.emplace(STR("__vecDelDtor"), 0x0);
}

if (auto it = FExec::VTableLayoutMap.find(STR("Exec")); it == FExec::VTableLayoutMap.end())
{
    FExec::VTableLayoutMap.emplace(STR("Exec"), 0x8);
}

