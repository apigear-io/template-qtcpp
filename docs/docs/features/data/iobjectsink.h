class IObjectSink {
public:
    virtual std::string olinkObjectName() = 0;
    virtual void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) = 0;
    virtual void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) = 0;
    virtual void olinkOnInit(const std::string& objectId, const nlohmann::json& props, IClientNode* node) = 0;
    virtual void olinkOnRelease() = 0;
};