if (auto it = UObjectBaseUtility::VTableLayoutMap.find(STR("__vecDelDtor_2")); it == UObjectBaseUtility::VTableLayoutMap.end())
{
    UObjectBaseUtility::VTableLayoutMap.emplace(STR("__vecDelDtor_2"), 0x0);
}

if (auto it = UObjectBaseUtility::VTableLayoutMap.find(STR("CanBeClusterRoot")); it == UObjectBaseUtility::VTableLayoutMap.end())
{
    UObjectBaseUtility::VTableLayoutMap.emplace(STR("CanBeClusterRoot"), 0x18);
}

if (auto it = UObjectBaseUtility::VTableLayoutMap.find(STR("CanBeInCluster")); it == UObjectBaseUtility::VTableLayoutMap.end())
{
    UObjectBaseUtility::VTableLayoutMap.emplace(STR("CanBeInCluster"), 0x20);
}

if (auto it = UObjectBaseUtility::VTableLayoutMap.find(STR("CreateCluster")); it == UObjectBaseUtility::VTableLayoutMap.end())
{
    UObjectBaseUtility::VTableLayoutMap.emplace(STR("CreateCluster"), 0x28);
}

if (auto it = UObjectBaseUtility::VTableLayoutMap.find(STR("OnClusterMarkedAsPendingKill")); it == UObjectBaseUtility::VTableLayoutMap.end())
{
    UObjectBaseUtility::VTableLayoutMap.emplace(STR("OnClusterMarkedAsPendingKill"), 0x30);
}

