// In-memory reactive node

#pragma once

#include "../../reactive/in-memory/InMemorySubject.h"
#include "../ReactiveNodeIf.h"

namespace reactive {
namespace graph {

using std::future;
using std::shared_ptr;
using NodeT = reactive::graph::NodeIf;

class InMemoryReactiveNode: public virtual ReactiveNodeIf {
public:
	InMemoryReactiveNode(Identity id): id_ {id} { }

	// ObservableIf
	future<SubscriptionIf<NodeT>> subscribe(shared_ptr<ObserverIf<NodeT>>) override;

	// ObserverIf
	future<void> next(const NodeT&) override;
	future<void> error(const NodeT&) override;
	future<void> complete() override;

	// ReactiveNodeIf
	future<Identity> getStreamId() const override;

	// NodeIf
	future<Identity> getId() const override;
	future<Properties> getProperties() const override;
	future<Edges> getIncomingEdges() const override;
	future<Edges> getOutgoingEdges() const override;

	future<void> setProperty(const uri&, const Value &) override;
	future<void> addIncomingEdge(const Identity&) override;
	future<void> addOutgoingEdge(const Identity&) override;

private:
	InMemorySubject<NodeT> subject_;
  Identity id_;
  Identity streamId_;
  Properties properties_;
  Edges incomingEdges_;
  Edges outgoingEdges_;
};

}
}
