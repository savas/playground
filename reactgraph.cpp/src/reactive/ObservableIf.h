// Observable abstraction

#pragma once

#include <future>
#include <memory>

#include "ObserverIf.h"
#include "SubscriptionIf.h"

namespace reactive {

using std::shared_ptr;

template<typename T>
class ObservableIf {
public:
	virtual ~ObservableIf() = default;

	virtual std::future<SubscriptionIf<T>> subscribe(shared_ptr<ObserverIf<T>>) = 0;
};

}
