// In-memory reactive node

#pragma once

#include "../../reactive/in-memory/InMemorySubject.h"
#include "../ReactiveNode.h"

namespace reactive {
namespace graph {

class InMemoryReactiveNode: ReactiveNode {
public:
	std::future<SubscriptionIf<reactive::graph::Node>> subscribe(
			const ObserverIf<reactive::graph::Node>&) override;

private:
	reactive::InMemorySubject<reactive::graph::Node> subject_;
};

}
}
