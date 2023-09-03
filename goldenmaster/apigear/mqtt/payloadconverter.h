#pragma once

#include <QtCore>
#include "mqtt_common.h"
#include <nlohmann/json.hpp>
#include <atomic>

namespace ApiGear {
namespace Mqtt {

// Helper class for generating ids.
// WARNING this is simplest approach, will work only until overflow of quint64.
class UniqueIdGenerator
{
public:
    quint64 getId()
    {
        return current++;
    }
private:
    std::atomic<quint64> current = 0ul;
};


namespace PayloadConverter
{
/** Converts a raw payload in form of QByteArray to nlohmann::json 
*   @param payload. Raw data in form of QByteArray, that was filled with nlohmann::json data.
*   @return a data converted back to nlohmann::json format
*   see complementary function: QByteArray toPayload(const nlohmann::json& data).
*/
APIGEAR_MQTT_EXPORT nlohmann::json fromPayload(const QByteArray& payload);

/** Fills a QByteArray with data in nlohmann::json format.
*   @param  data. Data to put into QByteArray
*   @return QByteArray with data which were represented with nlohmann::json
*   see complementary function: nlohmann::json fromPayload(const QByteArray& payload).
*/
APIGEAR_MQTT_EXPORT QByteArray toPayload(const nlohmann::json& data);

/** Reads parameters form a QByteArray.
*   @param payload. Raw data in form of QByteArray, from which output parameters are read.
*   @...output. Parameters to which data should be read. Each parameter has to be one of Qt embedded types.
*   see complementary function: toPayload( const Parameters*  ...inputs)
*/
template<typename ... Parameters>
void fromPayload(QByteArray& payload, Parameters*  ...outputs)
{
    QBuffer buffer(&payload);
    buffer.open(QIODevice::ReadOnly);
    QDataStream in(&buffer);
    int i = 0;
    ([&]
     {
         in >> outputs[i];
         ++i;
     }(), ...);
    buffer.close();
}

/** Writes a content of a number of parameters into  QByteArray. Qt embedded types
*   @param payload. Raw data in form of QByteArray, from which output parameters should be read.
*   @...output. Parameters to write into QByteArray. Each parameter has to be one of Qt embedded types.
*   see complementary function: fromPayload( const Parameters*  ...outputs)
*/
template<typename ... Parameters>
QByteArray toPayload( const Parameters*  ...inputs)
{
    QByteArray payload;
    QBuffer buffer(&payload);
    buffer.open(QIODevice::WriteOnly);
    QDataStream out(&buffer);

    int i = 0;
    ([&]
     {
         out << inputs[i];
         ++i;
     }(), ...);
    buffer.close();
    return payload;
}

}}} // namespace ApiGear::Mqtt::PayloadConverter
