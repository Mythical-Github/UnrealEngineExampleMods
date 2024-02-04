if (auto it = AHUD::MemberOffsets.find(STR("DebugDisplay")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("DebugDisplay"), 0x3B8);
}

if (auto it = AHUD::MemberOffsets.find(STR("DebugTextList")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("DebugTextList"), 0x3E8);
}

if (auto it = AHUD::MemberOffsets.find(STR("GreenColor")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("GreenColor"), 0x384);
}

if (auto it = AHUD::MemberOffsets.find(STR("HitBoxHits")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("HitBoxHits"), 0x420);
}

if (auto it = AHUD::MemberOffsets.find(STR("HitBoxMap")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("HitBoxMap"), 0x410);
}

if (auto it = AHUD::MemberOffsets.find(STR("LastHUDRenderTime")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("LastHUDRenderTime"), 0x3B0);
}

if (auto it = AHUD::MemberOffsets.find(STR("PostRenderedActors")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("PostRenderedActors"), 0x3A0);
}

if (auto it = AHUD::MemberOffsets.find(STR("RedColor")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("RedColor"), 0x388);
}

if (auto it = AHUD::MemberOffsets.find(STR("RenderDelta")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("RenderDelta"), 0x3B4);
}

if (auto it = AHUD::MemberOffsets.find(STR("ShowDebugTargetActor")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("ShowDebugTargetActor"), 0x408);
}

if (auto it = AHUD::MemberOffsets.find(STR("ShowDebugTargetDesiredClass")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("ShowDebugTargetDesiredClass"), 0x400);
}

if (auto it = AHUD::MemberOffsets.find(STR("ToggledDebugCategories")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("ToggledDebugCategories"), 0x3C8);
}

if (auto it = AHUD::MemberOffsets.find(STR("WhiteColor")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("WhiteColor"), 0x380);
}

if (auto it = AHUD::MemberOffsets.find(STR("bEnableDebugTextShadow")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bEnableDebugTextShadow"), 0x398);
}

if (auto it = AHUD::MemberOffsets.find(STR("bLostFocusPaused")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bLostFocusPaused"), 0x398);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowDebugForReticleTarget")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowDebugForReticleTarget"), 0x3F8);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowDebugInfo")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowDebugInfo"), 0x398);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowHUD")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowHUD"), 0x398);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowHitBoxDebugInfo")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowHitBoxDebugInfo"), 0x398);
}

if (auto it = AHUD::MemberOffsets.find(STR("bShowOverlays")); it == AHUD::MemberOffsets.end())
{
    AHUD::MemberOffsets.emplace(STR("bShowOverlays"), 0x398);
}

