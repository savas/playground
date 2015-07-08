// Node abstraction

#pragma once

#include <vector>
#include "Primitives.h"

namespace reactive {
namespace graph {

class Node {
  public:
    Identity id;
    Properties properties;
    std::vector<Identity> incomingEdges;
    std::vector<Identity> outgoingEdges;
};

}
}
