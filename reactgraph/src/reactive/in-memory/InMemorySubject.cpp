// In-memory stream

#include "InMemorySubject.h"
#include "InMemorySubscription.h"

namespace reactive {

using std::future;
using std::promise;

template<typename T>
future<SubscriptionIf<T>> InMemorySubject<T>::subscribe(
		const ObserverIf<T>& observer) {
	observers_.push_back(observer);

	return promise<SubscriptionIf<T>>().get_future();
}

template<typename T>
future<void> InMemorySubject<T>::next(const T& event) {
	for (auto observer: observers_) {
		observer.next(event);
	}
}

template<typename T>
future<void> InMemorySubject<T>::error(const T& event) {
	for (auto observer: observers_) {
		observer.error(event);
	}
}

template<typename T>
future<void> InMemorySubject<T>::complete() {
	for (auto observer: observers_) {
		observer.complete();
	}
}

}
