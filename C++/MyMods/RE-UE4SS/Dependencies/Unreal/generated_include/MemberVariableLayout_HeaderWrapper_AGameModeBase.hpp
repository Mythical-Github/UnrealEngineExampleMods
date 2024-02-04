static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    FText& GetDefaultPlayerName();
    const FText& GetDefaultPlayerName() const;

public:
    TObjectPtr<AGameSession>& GetGameSession();
    const TObjectPtr<AGameSession>& GetGameSession() const;

public:
    TSubclassOf<AGameSession>& GetGameSessionClass();
    const TSubclassOf<AGameSession>& GetGameSessionClass() const;

public:
    TSubclassOf<AHUD>& GetHUDClass();
    const TSubclassOf<AHUD>& GetHUDClass() const;

public:
    FString& GetOptionsString();
    const FString& GetOptionsString() const;

public:
    TSubclassOf<APlayerState>& GetPlayerStateClass();
    const TSubclassOf<APlayerState>& GetPlayerStateClass() const;

public:
    TObjectPtr<AServerStatReplicator>& GetServerStatReplicator();
    const TObjectPtr<AServerStatReplicator>& GetServerStatReplicator() const;

public:
    TSubclassOf<AServerStatReplicator>& GetServerStatReplicatorClass();
    const TSubclassOf<AServerStatReplicator>& GetServerStatReplicatorClass() const;

public:
    TSubclassOf<ASpectatorPawn>& GetSpectatorClass();
    const TSubclassOf<ASpectatorPawn>& GetSpectatorClass() const;

public:
    uint32& GetbPauseable();
    const uint32& GetbPauseable() const;

public:
    uint32& GetbStartPlayersAsSpectators();
    const uint32& GetbStartPlayersAsSpectators() const;

public:
    uint32& GetbUseSeamlessTravel();
    const uint32& GetbUseSeamlessTravel() const;

