static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    TEnumAsByte<enum EAspectRatioAxisConstraint>& GetAspectRatioAxisConstraint();
    const TEnumAsByte<enum EAspectRatioAxisConstraint>& GetAspectRatioAxisConstraint() const;

public:
    int32& GetControllerId();
    const int32& GetControllerId() const;

public:
    FVector& GetLastViewLocation();
    const FVector& GetLastViewLocation() const;

public:
    TObjectPtr<UGameViewportClient>& GetViewportClient();
    const TObjectPtr<UGameViewportClient>& GetViewportClient() const;

public:
    uint32& GetbSentSplitJoin();
    const uint32& GetbSentSplitJoin() const;

