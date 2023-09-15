#include "payloadconverter.h"

namespace ApiGear {
namespace Mqtt {

namespace PayloadConverter
{

nlohmann::json fromPayload(const QByteArray& payload)
{
    auto string = QString::fromUtf8(payload);
    auto value = nlohmann::json::parse(string.toStdString());
    return value;
}

QByteArray toPayload(const nlohmann::json& data)
{
    auto string = data.dump();
    auto stringData = QString::fromStdString(string);
    return stringData.toUtf8();
}

void fromPayload(const QByteArray& payload, QString* output)
{
    *output = QString::fromUtf8(payload);
}

QByteArray toPayload(const QString& input)
{
    return input.toUtf8();
}

}}} // namespace ApiGear::Mqtt::PayloadConverter
