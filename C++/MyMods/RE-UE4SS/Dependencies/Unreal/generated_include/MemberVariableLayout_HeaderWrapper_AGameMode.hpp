static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    int32& GetCurrentID();
    const int32& GetCurrentID() const;

public:
    FText& GetDefaultPlayerName();
    const FText& GetDefaultPlayerName() const;

public:
    TSubclassOf<ULocalMessage>& GetEngineMessageClass();
    const TSubclassOf<ULocalMessage>& GetEngineMessageClass() const;

public:
    TArray<FGameClassShortName,FDefaultAllocator>& GetGameModeClassAliases();
    const TArray<FGameClassShortName,FDefaultAllocator>& GetGameModeClassAliases() const;

public:
    AGameSession*& GetGameSession();
    const AGameSession*& GetGameSession() const;

public:
    TSubclassOf<AHUD>& GetHUDClass();
    const TSubclassOf<AHUD>& GetHUDClass() const;

public:
    TArray<TObjectPtr<APlayerState>,TSizedDefaultAllocator<32> >& GetInactivePlayerArray();
    const TArray<TObjectPtr<APlayerState>,TSizedDefaultAllocator<32> >& GetInactivePlayerArray() const;

public:
    float& GetInactivePlayerStateLifeSpan();
    const float& GetInactivePlayerStateLifeSpan() const;

public:
    FName& GetMatchState();
    const FName& GetMatchState() const;

public:
    int32& GetMaxInactivePlayers();
    const int32& GetMaxInactivePlayers() const;

public:
    float& GetMinRespawnDelay();
    const float& GetMinRespawnDelay() const;

public:
    int32& GetNumBots();
    const int32& GetNumBots() const;

public:
    int32& GetNumPlayers();
    const int32& GetNumPlayers() const;

public:
    int32& GetNumSpectators();
    const int32& GetNumSpectators() const;

public:
    int32& GetNumTravellingPlayers();
    const int32& GetNumTravellingPlayers() const;

public:
    FString& GetOptionsString();
    const FString& GetOptionsString() const;

public:
    TSubclassOf<APlayerState>& GetPlayerStateClass();
    const TSubclassOf<APlayerState>& GetPlayerStateClass() const;

public:
    TSubclassOf<ASpectatorPawn>& GetSpectatorClass();
    const TSubclassOf<ASpectatorPawn>& GetSpectatorClass() const;

public:
    uint32& GetbDelayedStart();
    const uint32& GetbDelayedStart() const;

public:
    bool& GetbHandleDedicatedServerReplays();
    const bool& GetbHandleDedicatedServerReplays() const;

public:
    uint32& GetbPauseable();
    const uint32& GetbPauseable() const;

public:
    uint32& GetbStartPlayersAsSpectators();
    const uint32& GetbStartPlayersAsSpectators() const;

public:
    uint32& GetbUseSeamlessTravel();
    const uint32& GetbUseSeamlessTravel() const;

