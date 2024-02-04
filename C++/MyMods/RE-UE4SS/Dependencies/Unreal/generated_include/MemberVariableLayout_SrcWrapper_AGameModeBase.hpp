std::unordered_map<File::StringType, int32_t> AGameModeBase::MemberOffsets{};

FText& AGameModeBase::GetDefaultPlayerName()
{
    static auto offset = MemberOffsets.find(STR("DefaultPlayerName"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::DefaultPlayerName' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FText*>(this, offset->second);
}
const FText& AGameModeBase::GetDefaultPlayerName() const
{
    static auto offset = MemberOffsets.find(STR("DefaultPlayerName"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::DefaultPlayerName' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FText*>(this, offset->second);
}

TObjectPtr<AGameSession>& AGameModeBase::GetGameSession()
{
    static auto offset = MemberOffsets.find(STR("GameSession"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::GameSession' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TObjectPtr<AGameSession>*>(this, offset->second);
}
const TObjectPtr<AGameSession>& AGameModeBase::GetGameSession() const
{
    static auto offset = MemberOffsets.find(STR("GameSession"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::GameSession' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TObjectPtr<AGameSession>*>(this, offset->second);
}

TSubclassOf<AGameSession>& AGameModeBase::GetGameSessionClass()
{
    static auto offset = MemberOffsets.find(STR("GameSessionClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::GameSessionClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TSubclassOf<AGameSession>*>(this, offset->second);
}
const TSubclassOf<AGameSession>& AGameModeBase::GetGameSessionClass() const
{
    static auto offset = MemberOffsets.find(STR("GameSessionClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::GameSessionClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TSubclassOf<AGameSession>*>(this, offset->second);
}

TSubclassOf<AHUD>& AGameModeBase::GetHUDClass()
{
    static auto offset = MemberOffsets.find(STR("HUDClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::HUDClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TSubclassOf<AHUD>*>(this, offset->second);
}
const TSubclassOf<AHUD>& AGameModeBase::GetHUDClass() const
{
    static auto offset = MemberOffsets.find(STR("HUDClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::HUDClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TSubclassOf<AHUD>*>(this, offset->second);
}

FString& AGameModeBase::GetOptionsString()
{
    static auto offset = MemberOffsets.find(STR("OptionsString"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::OptionsString' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FString*>(this, offset->second);
}
const FString& AGameModeBase::GetOptionsString() const
{
    static auto offset = MemberOffsets.find(STR("OptionsString"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::OptionsString' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FString*>(this, offset->second);
}

TSubclassOf<APlayerState>& AGameModeBase::GetPlayerStateClass()
{
    static auto offset = MemberOffsets.find(STR("PlayerStateClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::PlayerStateClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TSubclassOf<APlayerState>*>(this, offset->second);
}
const TSubclassOf<APlayerState>& AGameModeBase::GetPlayerStateClass() const
{
    static auto offset = MemberOffsets.find(STR("PlayerStateClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::PlayerStateClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TSubclassOf<APlayerState>*>(this, offset->second);
}

TObjectPtr<AServerStatReplicator>& AGameModeBase::GetServerStatReplicator()
{
    static auto offset = MemberOffsets.find(STR("ServerStatReplicator"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::ServerStatReplicator' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TObjectPtr<AServerStatReplicator>*>(this, offset->second);
}
const TObjectPtr<AServerStatReplicator>& AGameModeBase::GetServerStatReplicator() const
{
    static auto offset = MemberOffsets.find(STR("ServerStatReplicator"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::ServerStatReplicator' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TObjectPtr<AServerStatReplicator>*>(this, offset->second);
}

TSubclassOf<AServerStatReplicator>& AGameModeBase::GetServerStatReplicatorClass()
{
    static auto offset = MemberOffsets.find(STR("ServerStatReplicatorClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::ServerStatReplicatorClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TSubclassOf<AServerStatReplicator>*>(this, offset->second);
}
const TSubclassOf<AServerStatReplicator>& AGameModeBase::GetServerStatReplicatorClass() const
{
    static auto offset = MemberOffsets.find(STR("ServerStatReplicatorClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::ServerStatReplicatorClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TSubclassOf<AServerStatReplicator>*>(this, offset->second);
}

TSubclassOf<ASpectatorPawn>& AGameModeBase::GetSpectatorClass()
{
    static auto offset = MemberOffsets.find(STR("SpectatorClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::SpectatorClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TSubclassOf<ASpectatorPawn>*>(this, offset->second);
}
const TSubclassOf<ASpectatorPawn>& AGameModeBase::GetSpectatorClass() const
{
    static auto offset = MemberOffsets.find(STR("SpectatorClass"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::SpectatorClass' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TSubclassOf<ASpectatorPawn>*>(this, offset->second);
}

uint32& AGameModeBase::GetbPauseable()
{
    static auto offset = MemberOffsets.find(STR("bPauseable"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::bPauseable' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& AGameModeBase::GetbPauseable() const
{
    static auto offset = MemberOffsets.find(STR("bPauseable"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::bPauseable' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint32& AGameModeBase::GetbStartPlayersAsSpectators()
{
    static auto offset = MemberOffsets.find(STR("bStartPlayersAsSpectators"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::bStartPlayersAsSpectators' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& AGameModeBase::GetbStartPlayersAsSpectators() const
{
    static auto offset = MemberOffsets.find(STR("bStartPlayersAsSpectators"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::bStartPlayersAsSpectators' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

uint32& AGameModeBase::GetbUseSeamlessTravel()
{
    static auto offset = MemberOffsets.find(STR("bUseSeamlessTravel"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::bUseSeamlessTravel' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint32*>(this, offset->second);
}
const uint32& AGameModeBase::GetbUseSeamlessTravel() const
{
    static auto offset = MemberOffsets.find(STR("bUseSeamlessTravel"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AGameModeBase::bUseSeamlessTravel' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint32*>(this, offset->second);
}

