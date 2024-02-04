static std::unordered_map<File::StringType, int32_t> MemberOffsets;

public:
    int32& GetConfiguredInternetSpeed();
    const int32& GetConfiguredInternetSpeed() const;

public:
    int32& GetConfiguredLanSpeed();
    const int32& GetConfiguredLanSpeed() const;

public:
    int32& GetCurrentNetSpeed();
    const int32& GetCurrentNetSpeed() const;

