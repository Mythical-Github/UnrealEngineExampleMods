if (auto it = AGameModeBase::MemberOffsets.find(STR("DefaultPlayerName")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("DefaultPlayerName"), 0x288);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("GameSession")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("GameSession"), 0x270);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("GameSessionClass")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("GameSessionClass"), 0x228);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("HUDClass")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("HUDClass"), 0x248);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("OptionsString")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("OptionsString"), 0x218);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("Pausers")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("Pausers"), 0x2A8);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("PlayerStateClass")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("PlayerStateClass"), 0x240);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("ServerStatReplicator")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("ServerStatReplicator"), 0x280);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("ServerStatReplicatorClass")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("ServerStatReplicatorClass"), 0x268);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("SpectatorClass")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("SpectatorClass"), 0x258);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("bPauseable")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("bPauseable"), 0x2A0);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("bStartPlayersAsSpectators")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("bStartPlayersAsSpectators"), 0x2A0);
}

if (auto it = AGameModeBase::MemberOffsets.find(STR("bUseSeamlessTravel")); it == AGameModeBase::MemberOffsets.end())
{
    AGameModeBase::MemberOffsets.emplace(STR("bUseSeamlessTravel"), 0x2A0);
}

