// StreamIf

#pragma once

#include <future>

#include "ObservableIf.h"
#include "ObserverIf.h"

namespace reactive {

template<typename T>
class SubjectIf: public ObserverIf<T>, public ObservableIf<T> {
public:
	virtual ~SubjectIf() = default;

};

}
