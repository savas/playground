
#include "InMemoryReactiveEdge.h"
#include "Utilities.h"

namespace reactive {
namespace graph {

using std::promise;

future<Identity> InMemoryReactiveEdge::getSource() const {
  return value<Identity>(source_);
}

future<Identity> InMemoryReactiveEdge::getPredicate() const {
  return value<Identity>(predicate_);
}

future<Identity> InMemoryReactiveEdge::getDestination() const {
  return value<Identity>(destination_);
}

future<void> InMemoryReactiveEdge::setSource(const Identity& source) {
	source_ = source;
	next(*this);
	return promise<void>().get_future();
}

future<void> InMemoryReactiveEdge::setPredicate(const Identity& predicate) {
	predicate_ = predicate;
	next(*this);
	return promise<void>().get_future();
}

future<void> InMemoryReactiveEdge::setDestination(const Identity& destination) {
	destination_ = destination;
	next(*this);
	return promise<void>().get_future();
}

}
}
