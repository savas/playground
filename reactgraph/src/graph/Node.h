// Node abstraction

#pragma once

#include <vector>
#include "Identity.h"
#include "Primitives.h"

namespace reactive {
namespace graph {

class Node {
public:
	Node() = default;
	~Node() = default;

	Node(const Node&) = default;
	Node& operator=(const Node&) = default;

	Node(Node&&) = default;
	Node& operator=(Node&&) = default;

  Identity id;
  Properties properties;
  std::vector<Identity> incomingEdges;
  std::vector<Identity> outgoingEdges;
};

}
}
