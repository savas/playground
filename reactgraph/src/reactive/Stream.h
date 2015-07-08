// StreamIf

#pragma once

#include <future>
#include "Subscriber.h"
#include "Subscription.h"

namespace reactive {

template<typename T>
class Stream {
  public:
	virtual ~Stream() = default;

    virtual std::future<Subscription<T>> subscribe(Subscriber<T>) = 0;
};

}
