if (auto it = AHUD::MemberOffsets.find(STR("DebugDisplay")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("DebugDisplay"), 0x3B0);
}

if (auto it = AHUD::MemberOffsets.find(STR("DebugTextList")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("DebugTextList"), 0x3E0);
}

if (auto it = AHUD::MemberOffsets.find(STR("HitBoxHits")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("HitBoxHits"), 0x410);
}

if (auto it = AHUD::MemberOffsets.find(STR("HitBoxMap")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("HitBoxMap"), 0x400);
}

if (auto it = AHUD::MemberOffsets.find(STR("LastHUDRenderTime")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("LastHUDRenderTime"), 0x3A8);
}

if (auto it = AHUD::MemberOffsets.find(STR("PostRenderedActors")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("PostRenderedActors"), 0x398);
}

if (auto it = AHUD::MemberOffsets.find(STR("RenderDelta")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("RenderDelta"), 0x3AC);
}

if (auto it = AHUD::MemberOffsets.find(STR("ShowDebugTargetActor")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("ShowDebugTargetActor"), 0x3F8);
}

if (auto it = AHUD::MemberOffsets.find(STR("ShowDebugTargetDesiredClass")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("ShowDebugTargetDesiredClass"), 0x3F0);
}

if (auto it = AHUD::MemberOffsets.find(STR("ToggledDebugCategories")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("ToggledDebugCategories"), 0x3C0);
}

if (auto it = AHUD::MemberOffsets.find(STR("bEnableDebugTextShadow")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bEnableDebugTextShadow"), 0x390);
}

if (auto it = AHUD::MemberOffsets.find(STR("bLostFocusPaused")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bLostFocusPaused"), 0x390);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowDebugForReticleTarget")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowDebugForReticleTarget"), 0x390);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowDebugInfo")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowDebugInfo"), 0x390);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowHUD")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowHUD"), 0x390);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowHitBoxDebugInfo")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowHitBoxDebugInfo"), 0x390);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowOverlays")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowOverlays"), 0x390);
}

