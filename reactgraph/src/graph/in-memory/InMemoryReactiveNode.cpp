/*
 * InMemoryReactiveNode.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: savasp
 */

#include "InMemoryReactiveNode.h"

namespace reactive {
namespace graph {

using reactive::graph::Node;
using std::future;
using std::promise;

future<SubscriptionIf<Node>> InMemoryReactiveNode::subscribe(
		const ObserverIf<reactive::graph::Node>& observer) {
	return subject_.subscribe(observer);
}

}
}
