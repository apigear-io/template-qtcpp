#include <QtMqtt>
#include <memory>

namespace ApiGear {
namespace Mqtt {
namespace multimap_helper {

    template<class InputIt>
    InputIt find_first_with_matching_topic(InputIt first, InputIt last, const QMqttTopicName& topic)
    {
        for (auto subscription = first; subscription != last; subscription++)
        {
            if (subscription.key().match(topic))
                return subscription;
        }
        return last;
    }
}
}
}
