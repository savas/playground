//
// Created by Savas Parastatidis on 7/9/15.
//

#pragma once

#include <future>

namespace reactive {
namespace graph {

using std::promise;
using std::future;

template<typename T>
future<T> value(const T& v) {
  promise<T> promise;
  promise.set_value(v);
  return promise.get_future();
}

}
}
