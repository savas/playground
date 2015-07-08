// Node abstraction

#pragma once

#include <vector>

#include "../reactive/SubjectIf.h"
#include "Node.h"

using namespace reactive;

namespace reactive {
namespace graph {

class ReactiveNode: SubjectIf<Node>, Node {
public:
	Identity streamId;

	virtual ~ReactiveNode() = default;
	virtual std::future<SubscriptionIf<Node>> subscribe(
			const ObserverIf<Node>&) = 0;
};

}
}
