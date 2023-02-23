class  IObjectSource {
public:
    virtual std::string olinkObjectName() = 0;
    virtual nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args) = 0;
    virtual void olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) = 0;
    virtual void olinkLinked(const std::string& objectId, IRemoteNode* node) = 0;
    virtual void olinkUnlinked(const std::string& objectId) = 0;
    virtual nlohmann::json olinkCollectProperties() = 0;
};
