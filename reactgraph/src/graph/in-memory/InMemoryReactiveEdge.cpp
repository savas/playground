
#include "InMemoryReactiveEdge.h"

namespace reactive {
namespace graph {

using std::promise;

future<Identity> InMemoryReactiveEdge::getSource() const {
	return promise<Identity>(source_).get_future();
}

future<Identity> InMemoryReactiveEdge::getPredicate() const {
	return promise<Identity>(predicate_).get_future();
}

future<Identity> InMemoryReactiveEdge::getDestination() const {
  return promise<Identity>(destination_).get_future();
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
