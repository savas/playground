// In-memory stream

#pragma once

#include <future>
#include <vector>

#include "../SubjectIf.h"

namespace reactive {

template<typename T>
class InMemorySubject: SubjectIf<T> {
public:
	std::future<SubscriptionIf<T>> subscribe(const ObserverIf<T>&) override;
	std::future<void> next(const T&) override;
	std::future<void> error(const T&) override;
	std::future<void> complete() override;

private:
	std::vector<ObserverIf<T>> observers_;
};

}
