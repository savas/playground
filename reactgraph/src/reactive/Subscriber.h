// Subscriber abstraction

#pragma once

#include <future>

namespace reactive {

template<typename T>
class Subscriber {
  public:
  	std::future<void> next(const T&);
	std::future<void> error(const T&);
	std::future<void> complete();
};

}
