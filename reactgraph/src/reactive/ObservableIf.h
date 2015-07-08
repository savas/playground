// Observable abstraction

#pragma once

#include <future>

#include "ObserverIf.h"
#include "SubscriptionIf.h"

namespace reactive {

template<typename T>
class ObservableIf {
public:
	virtual ~ObservableIf() = default;

	virtual std::future<SubscriptionIf<T>> subscribe(const ObserverIf<T>&) = 0;
};

}
