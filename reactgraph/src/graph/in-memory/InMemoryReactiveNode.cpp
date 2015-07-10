/*
 * InMemoryReactiveNode.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: savasp
 */

#include "InMemoryReactiveNode.h"
#include "Utilities.h"

namespace reactive {
namespace graph {

using std::promise;

future<SubscriptionIf<NodeT>> InMemoryReactiveNode::subscribe(
		shared_ptr<ObserverIf<NodeT>> observer) {
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
	return value<Identity>(streamId_);
}

future<Identity> InMemoryReactiveNode::getId() const {
	return value<Identity>(id_);
}

future<Properties> InMemoryReactiveNode::getProperties() const {
	return value<Properties>(properties_);
}

future<Edges> InMemoryReactiveNode::getIncomingEdges() const {
	return value<Edges>(incomingEdges_);
}

future<Edges> InMemoryReactiveNode::getOutgoingEdges() const {
	return value<Edges>(outgoingEdges_);
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
