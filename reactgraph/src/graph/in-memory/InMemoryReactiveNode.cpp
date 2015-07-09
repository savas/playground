/*
 * InMemoryReactiveNode.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: savasp
 */

#include "InMemoryReactiveNode.h"

namespace reactive {
namespace graph {

using std::promise;

future<SubscriptionIf<NodeT>> InMemoryReactiveNode::subscribe(
		const ObserverIf<NodeT>& observer) {
	return subject_.subscribe(observer);
}

future<void> InMemoryReactiveNode::next(const NodeT& node) {
	return subject_.next(node);
}

future<void> InMemoryReactiveNode::error(const NodeT& node) {
	return subject_.error(node);
}

future<void> InMemoryReactiveNode::complete() {
	return subject_.complete();
}

future<Identity> InMemoryReactiveNode::getStreamId() const {
	return promise<Identity>(streamId_).get_future();
}

future<Identity> InMemoryReactiveNode::getId() const {
	return promise<Identity>(id_).get_future();
}

future<Properties> InMemoryReactiveNode::getProperties() const {
	return promise<Properties>(properties_).get_future();
}

future<Edges> InMemoryReactiveNode::getIncomingEdges() const {
	return promise<Edges>(incomingEdges_).get_future();
}

future<Edges> InMemoryReactiveNode::getOutgoingEdges() const {
	return promise<Edges>(outgoingEdges_).get_future();
}

future<void> InMemoryReactiveNode::setProperty(const uri& name, const Value& value) {
	properties_[name] = value;
	next(*this);
	return promise<void>().get_future();
}

future<void> InMemoryReactiveNode::addIncomingEdge(const Identity& edgeId) {
  incomingEdges_.push_back(edgeId);
	next(*this);
	return promise<void>().get_future();
}

future<void> InMemoryReactiveNode::addOutgoingEdge(const Identity& edgeId) {
	outgoingEdges_.push_back(edgeId);
	next(*this);
	return promise<void>().get_future();
}

}
}
