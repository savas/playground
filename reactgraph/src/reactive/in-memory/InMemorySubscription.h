// In-memory stream

#include "../SubscriptionIf.h"

namespace reactive {

template<typename T>
class InMemorySubscription: SubscriptionIf<T> {
};

}
