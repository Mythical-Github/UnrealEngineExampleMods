if (auto it = AHUD::MemberOffsets.find(STR("CurrentTargetIndex")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("CurrentTargetIndex"), 0x224);
}

if (auto it = AHUD::MemberOffsets.find(STR("DebugDisplay")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("DebugDisplay"), 0x248);
}

if (auto it = AHUD::MemberOffsets.find(STR("DebugTextList")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("DebugTextList"), 0x278);
}

if (auto it = AHUD::MemberOffsets.find(STR("HitBoxHits")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("HitBoxHits"), 0x2A8);
}

if (auto it = AHUD::MemberOffsets.find(STR("HitBoxMap")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("HitBoxMap"), 0x298);
}

if (auto it = AHUD::MemberOffsets.find(STR("LastHUDRenderTime")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("LastHUDRenderTime"), 0x240);
}

if (auto it = AHUD::MemberOffsets.find(STR("PostRenderedActors")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("PostRenderedActors"), 0x230);
}

if (auto it = AHUD::MemberOffsets.find(STR("RenderDelta")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("RenderDelta"), 0x244);
}

if (auto it = AHUD::MemberOffsets.find(STR("ShowDebugTargetActor")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("ShowDebugTargetActor"), 0x290);
}

if (auto it = AHUD::MemberOffsets.find(STR("ShowDebugTargetDesiredClass")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("ShowDebugTargetDesiredClass"), 0x288);
}

if (auto it = AHUD::MemberOffsets.find(STR("ToggledDebugCategories")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("ToggledDebugCategories"), 0x258);
}

if (auto it = AHUD::MemberOffsets.find(STR("bEnableDebugTextShadow")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bEnableDebugTextShadow"), 0x228);
}

if (auto it = AHUD::MemberOffsets.find(STR("bLostFocusPaused")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bLostFocusPaused"), 0x220);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowDebugForReticleTarget")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowDebugForReticleTarget"), 0x228);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowDebugInfo")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowDebugInfo"), 0x220);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowHUD")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowHUD"), 0x220);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowHitBoxDebugInfo")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowHitBoxDebugInfo"), 0x228);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowOverlays")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowOverlays"), 0x228);
}

