// Subscriber abstraction

#pragma once

#include <future>

namespace reactive {

template<typename T>
class ObserverIf {
public:
	virtual ~ObserverIf() = default;

	virtual std::future<void> next(const T&) = 0;
	virtual std::future<void> error(const T&) = 0;
	virtual std::future<void> complete() = 0;
};

}
