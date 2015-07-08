// StreamIf

#pragma once

#include <future>

#include "ObservableIf.h"
#include "ObserverIf.h"

namespace reactive {

template<typename T>
class SubjectIf: ObserverIf<T>, ObservableIf<T> {
public:
	virtual ~SubjectIf() = default;

};

}
