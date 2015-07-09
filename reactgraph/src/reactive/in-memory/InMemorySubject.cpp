// In-memory stream

#include "InMemorySubject.h"
#include "InMemorySubscription.h"

namespace reactive {

using std::promise;

template<typename T>
future<SubscriptionIf<T>> InMemorySubject<T>::subscribe(
		const ObserverIf<T>& observer) {

	observableMutex_.lock();
	observers_.push_back(observer);
	observableMutex_.unlock();

	return promise<SubscriptionIf<T>>().get_future();
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
		function(observer);
	}
	observerMutex_.unlock();

	return promise<void>().get_future();
}

}
