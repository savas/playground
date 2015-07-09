// In-memory reactive edge

#pragma once

#include "../ReactiveEdgeIf.h"
#include "InMemoryReactiveNode.h"

namespace reactive {
namespace graph {

using std::future;

class InMemoryReactiveEdge: public InMemoryReactiveNode, public virtual ReactiveEdgeIf {
public:
	InMemoryReactiveEdge(Identity id): InMemoryReactiveNode {id} {}

	future<Identity> getSource() const override;
	future<Identity> getPredicate() const override;
	future<Identity> getDestination() const override;

	future<void> setSource(const Identity&) override;
	future<void> setPredicate(const Identity&) override;
	future<void> setDestination(const Identity&) override;

private:
  Identity source_;
  Identity predicate_;
  Identity destination_;
};

}
}
