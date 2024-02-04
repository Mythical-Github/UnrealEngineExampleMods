if (auto it = AGameMode::VTableLayoutMap.find(STR("__vecDelDtor_2")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("__vecDelDtor_2"), 0x0);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("ReadyToEndMatch_Implementation")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("ReadyToEndMatch_Implementation"), 0x820);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("ReadyToStartMatch_Implementation")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("ReadyToStartMatch_Implementation"), 0x828);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("IsMatchInProgress")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("IsMatchInProgress"), 0x830);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("StartMatch")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("StartMatch"), 0x838);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("EndMatch")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("EndMatch"), 0x840);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("RestartGame")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("RestartGame"), 0x848);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("AbortMatch")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("AbortMatch"), 0x850);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("SetMatchState")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("SetMatchState"), 0x858);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("OnMatchStateSet")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("OnMatchStateSet"), 0x860);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("HandleMatchIsWaitingToStart")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("HandleMatchIsWaitingToStart"), 0x868);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("HandleMatchHasStarted")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("HandleMatchHasStarted"), 0x870);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("HandleMatchHasEnded")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("HandleMatchHasEnded"), 0x878);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("HandleLeavingMap")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("HandleLeavingMap"), 0x880);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("HandleMatchAborted")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("HandleMatchAborted"), 0x888);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("GetNetworkNumber")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("GetNetworkNumber"), 0x890);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("GetDefaultGameClassPath")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("GetDefaultGameClassPath"), 0x898);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("GetGameModeClass")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("GetGameModeClass"), 0x8A0);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("GetTravelType")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("GetTravelType"), 0x8A8);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("SendPlayer")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("SendPlayer"), 0x8B0);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("StartNewPlayer")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("StartNewPlayer"), 0x8B8);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("Say")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("Say"), 0x8C0);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("SetBandwidthLimit")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("SetBandwidthLimit"), 0x8C8);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("Broadcast")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("Broadcast"), 0x8D0);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("BroadcastLocalized")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("BroadcastLocalized"), 0x8D8);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("AddInactivePlayer")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("AddInactivePlayer"), 0x8E0);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("FindInactivePlayer")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("FindInactivePlayer"), 0x8E8);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("OverridePlayerState")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("OverridePlayerState"), 0x8F0);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("SetSeamlessTravelViewTarget")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("SetSeamlessTravelViewTarget"), 0x8F8);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("MatineeCancelled")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("MatineeCancelled"), 0x900);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("PreCommitMapChange")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("PreCommitMapChange"), 0x908);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("PostCommitMapChange")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("PostCommitMapChange"), 0x910);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("NotifyPendingConnectionLost")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("NotifyPendingConnectionLost"), 0x918);
}

if (auto it = AGameMode::VTableLayoutMap.find(STR("HandleDisconnect")); it == AGameMode::VTableLayoutMap.end())
{
    AGameMode::VTableLayoutMap.emplace(STR("HandleDisconnect"), 0x920);
}

