// Node abstraction

#pragma once

#include <vector>
#include "Node.h"
#include "../reactive/Stream.h"

using namespace reactive;

namespace reactive {
namespace graph {

class ReactiveNode: Stream<Node>, Node {
  public:
    Identity streamId;
    
    std::future<Subscription<Node>> subscribe(Subscriber<Node>);
};

}
}
