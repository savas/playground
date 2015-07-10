// In-memory observer

#pragma once

#include <future>
#include "../ObserverIf.h"

namespace reactive {

using std::function;
using std::future;

template<typename T>
class InMemoryLambdaObserver: public ObserverIf<T> {
public:
  InMemoryLambdaObserver(function<void(const T&)> callback): function_ {callback} {}
	future<void> next(const T&) override;
	future<void> error(const T&) override;
	future<void> complete() override;

private:
  bool complete_ = false;
  function<void(const T&)> function_;
};

template<typename T>
future<void> InMemoryLambdaObserver<T>::next(const T& event) {
  if (!complete_) {
    function_(event);
  }

  return promise<void>().get_future();
}

template<typename T>
future<void> InMemoryLambdaObserver<T>::error(const T& event) {
  throw "not implemented yet";
}

template<typename T>
future<void> InMemoryLambdaObserver<T>::complete() {
  complete_ = true;

  return promise<void>().get_future();
}

}
