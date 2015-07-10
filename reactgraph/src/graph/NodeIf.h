// Node abstraction

#pragma once

#include <map>
#include <vector>

#include "Identity.h"
#include "Value.h"

namespace reactive {
namespace graph {

using network::uri;
using std::future;
using std::map;
using std::vector;
using Properties = map<uri, Value>;
using Edges = vector<Identity>;

class NodeIf {
public:
	virtual ~NodeIf() = default;

	virtual future<Identity> getId() const = 0;
	virtual future<Properties> getProperties() const = 0;
	virtual future<Edges> getIncomingEdges() const = 0;
	virtual future<Edges> getOutgoingEdges() const = 0;

	virtual future<void> setProperty(const uri&, const Value&) = 0;
	virtual future<void> addIncomingEdge(const Identity&) = 0;
	virtual future<void> addOutgoingEdge(const Identity&) = 0;
};

}
}
