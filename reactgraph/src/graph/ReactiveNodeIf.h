// Node abstraction

#pragma once

#include <vector>

#include "../reactive/SubjectIf.h"
#include "NodeIf.h"

namespace reactive {
namespace graph {

class ReactiveNodeIf: public SubjectIf<NodeIf>, public virtual NodeIf {
public:
	virtual ~ReactiveNodeIf() = default;
	virtual future<Identity> getStreamId() const = 0;
};

}
}
