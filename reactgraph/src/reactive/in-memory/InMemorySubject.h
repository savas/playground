// In-memory stream

#pragma once

#include <future>
#include <mutex>
#include <vector>

#include "../SubjectIf.h"

namespace reactive {

using std::function;
using std::future;
using std::mutex;
using std::vector;

template<typename T>
class InMemorySubject: SubjectIf<T> {
public:
	future<SubscriptionIf<T>> subscribe(const ObserverIf<T>&) override;
	future<void> next(const T&) override;
	future<void> error(const T&) override;
	future<void> complete() override;

private:
	vector<ObserverIf<T>> observers_;
	mutex observerMutex_;
	mutex observableMutex_;

	future<void> forAllObservers(function<void (ObserverIf<T>&)>);
};

}
