if (auto it = AGameModeBase::MemberOffsets.find(STR("DefaultPlayerName")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("DefaultPlayerName"), 0x290);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("GameSession")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("GameSession"), 0x278);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("GameSessionClass")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("GameSessionClass"), 0x230);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("HUDClass")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("HUDClass"), 0x250);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("OptionsString")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("OptionsString"), 0x220);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("PlayerStateClass")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("PlayerStateClass"), 0x248);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("ServerStatReplicator")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("ServerStatReplicator"), 0x288);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("ServerStatReplicatorClass")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("ServerStatReplicatorClass"), 0x270);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("SpectatorClass")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("SpectatorClass"), 0x260);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("bPauseable")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("bPauseable"), 0x2A8);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("bStartPlayersAsSpectators")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("bStartPlayersAsSpectators"), 0x2A8);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("bUseSeamlessTravel")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("bUseSeamlessTravel"), 0x2A8);
}

