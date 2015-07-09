// Reactive Edge

#pragma once

#include "ReactiveNodeIf.h"
#include "EdgeIf.h"

namespace reactive {
namespace graph {

class ReactiveEdgeIf: public virtual EdgeIf, public virtual ReactiveNodeIf {
};

}
}
