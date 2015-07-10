// In-memory stream

#pragma once

#include <future>
#include <mutex>
#include <vector>

#include "../SubjectIf.h"
#include "InMemorySubscription.h"

namespace reactive {

using std::function;
using std::future;
using std::move;
using std::mutex;
using std::promise;
using std::vector;

template<typename T>
class InMemorySubject: public SubjectIf<T> {
public:
	future<SubscriptionIf<T>> subscribe(shared_ptr<ObserverIf<T>>) override;
	future<void> next(const T&) override;
	future<void> error(const T&) override;
	future<void> complete() override;

private:
	vector<shared_ptr<ObserverIf<T>>> observers_;
	mutex observerMutex_;
	mutex observableMutex_;

	future<void> forAllObservers(function<void (ObserverIf<T>&)>);
};

template<typename T>
future<SubscriptionIf<T>> InMemorySubject<T>::subscribe(shared_ptr<ObserverIf<T>> observer) {

	observableMutex_.lock();
	observers_.push_back(observer);
	observableMutex_.unlock();

	InMemorySubscription<T> subscription;
	promise<SubscriptionIf<T>> promise;
	promise.set_value(move(subscription));

	return promise.get_future();
}

template<typename T>
future<void> InMemorySubject<T>::next(const T& event) {
	return forAllObservers([&event](ObserverIf<T>& observer) {observer.next(event);});
}

template<typename T>
future<void> InMemorySubject<T>::error(const T& event) {
	return forAllObservers([&event](ObserverIf<T>& observer) {observer.error(event);});
}

template<typename T>
future<void> InMemorySubject<T>::complete() {
	return forAllObservers([](ObserverIf<T>& observer) {observer.complete();});
}

template<typename T>
future<void> InMemorySubject<T>::forAllObservers(
				function<void(ObserverIf<T>&)> function) {
	observerMutex_.lock();
	for (auto observer : observers_) {
		function(*observer);
	}
	observerMutex_.unlock();

	return promise<void>().get_future();
}

}
