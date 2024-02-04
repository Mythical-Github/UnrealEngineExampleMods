std::unordered_map<File::StringType, int32_t> AGameMode::MemberOffsets{};

int32& AGameMode::GetCurrentID()
{
    static auto offset = MemberOffsets.find(STR("CurrentID"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::CurrentID' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& AGameMode::GetCurrentID() const
{
    static auto offset = MemberOffsets.find(STR("CurrentID"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::CurrentID' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

FText& AGameMode::GetDefaultPlayerName()
{
    static auto offset = MemberOffsets.find(STR("DefaultPlayerName"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::DefaultPlayerName' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FText*>(this, offset->second);
}
const FText& AGameMode::GetDefaultPlayerName() const
{
    static auto offset = MemberOffsets.find(STR("DefaultPlayerName"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::DefaultPlayerName' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FText*>(this, offset->second);
}

TSubclassOf<ULocalMessage>& AGameMode::GetEngineMessageClass()
{
    static auto offset = MemberOffsets.find(STR("EngineMessageClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::EngineMessageClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TSubclassOf<ULocalMessage>*>(this, offset->second);
}
const TSubclassOf<ULocalMessage>& AGameMode::GetEngineMessageClass() const
{
    static auto offset = MemberOffsets.find(STR("EngineMessageClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::EngineMessageClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TSubclassOf<ULocalMessage>*>(this, offset->second);
}

TArray<FGameClassShortName,FDefaultAllocator>& AGameMode::GetGameModeClassAliases()
{
    static auto offset = MemberOffsets.find(STR("GameModeClassAliases"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::GameModeClassAliases' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FGameClassShortName,FDefaultAllocator>*>(this, offset->second);
}
const TArray<FGameClassShortName,FDefaultAllocator>& AGameMode::GetGameModeClassAliases() const
{
    static auto offset = MemberOffsets.find(STR("GameModeClassAliases"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::GameModeClassAliases' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FGameClassShortName,FDefaultAllocator>*>(this, offset->second);
}

AGameSession*& AGameMode::GetGameSession()
{
    static auto offset = MemberOffsets.find(STR("GameSession"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::GameSession' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<AGameSession**>(this, offset->second);
}
const AGameSession*& AGameMode::GetGameSession() const
{
    static auto offset = MemberOffsets.find(STR("GameSession"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::GameSession' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const AGameSession**>(this, offset->second);
}

TSubclassOf<AHUD>& AGameMode::GetHUDClass()
{
    static auto offset = MemberOffsets.find(STR("HUDClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::HUDClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TSubclassOf<AHUD>*>(this, offset->second);
}
const TSubclassOf<AHUD>& AGameMode::GetHUDClass() const
{
    static auto offset = MemberOffsets.find(STR("HUDClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::HUDClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TSubclassOf<AHUD>*>(this, offset->second);
}

TArray<TObjectPtr<APlayerState>,TSizedDefaultAllocator<32> >& AGameMode::GetInactivePlayerArray()
{
    static auto offset = MemberOffsets.find(STR("InactivePlayerArray"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::InactivePlayerArray' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<TObjectPtr<APlayerState>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<TObjectPtr<APlayerState>,TSizedDefaultAllocator<32> >& AGameMode::GetInactivePlayerArray() const
{
    static auto offset = MemberOffsets.find(STR("InactivePlayerArray"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::InactivePlayerArray' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<TObjectPtr<APlayerState>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

float& AGameMode::GetInactivePlayerStateLifeSpan()
{
    static auto offset = MemberOffsets.find(STR("InactivePlayerStateLifeSpan"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::InactivePlayerStateLifeSpan' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AGameMode::GetInactivePlayerStateLifeSpan() const
{
    static auto offset = MemberOffsets.find(STR("InactivePlayerStateLifeSpan"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::InactivePlayerStateLifeSpan' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

FName& AGameMode::GetMatchState()
{
    static auto offset = MemberOffsets.find(STR("MatchState"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::MatchState' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& AGameMode::GetMatchState() const
{
    static auto offset = MemberOffsets.find(STR("MatchState"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::MatchState' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

int32& AGameMode::GetMaxInactivePlayers()
{
    static auto offset = MemberOffsets.find(STR("MaxInactivePlayers"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::MaxInactivePlayers' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& AGameMode::GetMaxInactivePlayers() const
{
    static auto offset = MemberOffsets.find(STR("MaxInactivePlayers"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::MaxInactivePlayers' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

float& AGameMode::GetMinRespawnDelay()
{
    static auto offset = MemberOffsets.find(STR("MinRespawnDelay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::MinRespawnDelay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AGameMode::GetMinRespawnDelay() const
{
    static auto offset = MemberOffsets.find(STR("MinRespawnDelay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::MinRespawnDelay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

int32& AGameMode::GetNumBots()
{
    static auto offset = MemberOffsets.find(STR("NumBots"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::NumBots' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& AGameMode::GetNumBots() const
{
    static auto offset = MemberOffsets.find(STR("NumBots"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::NumBots' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

int32& AGameMode::GetNumPlayers()
{
    static auto offset = MemberOffsets.find(STR("NumPlayers"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::NumPlayers' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& AGameMode::GetNumPlayers() const
{
    static auto offset = MemberOffsets.find(STR("NumPlayers"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::NumPlayers' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

int32& AGameMode::GetNumSpectators()
{
    static auto offset = MemberOffsets.find(STR("NumSpectators"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::NumSpectators' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& AGameMode::GetNumSpectators() const
{
    static auto offset = MemberOffsets.find(STR("NumSpectators"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::NumSpectators' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

int32& AGameMode::GetNumTravellingPlayers()
{
    static auto offset = MemberOffsets.find(STR("NumTravellingPlayers"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::NumTravellingPlayers' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& AGameMode::GetNumTravellingPlayers() const
{
    static auto offset = MemberOffsets.find(STR("NumTravellingPlayers"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::NumTravellingPlayers' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

FString& AGameMode::GetOptionsString()
{
    static auto offset = MemberOffsets.find(STR("OptionsString"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::OptionsString' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FString*>(this, offset->second);
}
const FString& AGameMode::GetOptionsString() const
{
    static auto offset = MemberOffsets.find(STR("OptionsString"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::OptionsString' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FString*>(this, offset->second);
}

TSubclassOf<APlayerState>& AGameMode::GetPlayerStateClass()
{
    static auto offset = MemberOffsets.find(STR("PlayerStateClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::PlayerStateClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TSubclassOf<APlayerState>*>(this, offset->second);
}
const TSubclassOf<APlayerState>& AGameMode::GetPlayerStateClass() const
{
    static auto offset = MemberOffsets.find(STR("PlayerStateClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::PlayerStateClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TSubclassOf<APlayerState>*>(this, offset->second);
}

TSubclassOf<ASpectatorPawn>& AGameMode::GetSpectatorClass()
{
    static auto offset = MemberOffsets.find(STR("SpectatorClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::SpectatorClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TSubclassOf<ASpectatorPawn>*>(this, offset->second);
}
const TSubclassOf<ASpectatorPawn>& AGameMode::GetSpectatorClass() const
{
    static auto offset = MemberOffsets.find(STR("SpectatorClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::SpectatorClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TSubclassOf<ASpectatorPawn>*>(this, offset->second);
}

uint32& AGameMode::GetbDelayedStart()
{
    static auto offset = MemberOffsets.find(STR("bDelayedStart"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::bDelayedStart' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& AGameMode::GetbDelayedStart() const
{
    static auto offset = MemberOffsets.find(STR("bDelayedStart"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::bDelayedStart' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

bool& AGameMode::GetbHandleDedicatedServerReplays()
{
    static auto offset = MemberOffsets.find(STR("bHandleDedicatedServerReplays"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::bHandleDedicatedServerReplays' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<bool*>(this, offset->second);
}
const bool& AGameMode::GetbHandleDedicatedServerReplays() const
{
    static auto offset = MemberOffsets.find(STR("bHandleDedicatedServerReplays"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::bHandleDedicatedServerReplays' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const bool*>(this, offset->second);
}

uint32& AGameMode::GetbPauseable()
{
    static auto offset = MemberOffsets.find(STR("bPauseable"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::bPauseable' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& AGameMode::GetbPauseable() const
{
    static auto offset = MemberOffsets.find(STR("bPauseable"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::bPauseable' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint32& AGameMode::GetbStartPlayersAsSpectators()
{
    static auto offset = MemberOffsets.find(STR("bStartPlayersAsSpectators"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::bStartPlayersAsSpectators' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& AGameMode::GetbStartPlayersAsSpectators() const
{
    static auto offset = MemberOffsets.find(STR("bStartPlayersAsSpectators"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::bStartPlayersAsSpectators' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint32& AGameMode::GetbUseSeamlessTravel()
{
    static auto offset = MemberOffsets.find(STR("bUseSeamlessTravel"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::bUseSeamlessTravel' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& AGameMode::GetbUseSeamlessTravel() const
{
    static auto offset = MemberOffsets.find(STR("bUseSeamlessTravel"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameMode::bUseSeamlessTravel' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

