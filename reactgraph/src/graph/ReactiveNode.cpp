/*
 * ReactiveNode.cpp
 *
 *  Created on: Jul 7, 2015
 *      Author: savasp
 */

#include "ReactiveNode.h"

namespace reactive {
namespace graph {

using namespace std;

future<Subscription<Node>> ReactiveNode::subscribe(Subscriber<Node>) {
  throw "not implemented yet";
}


}
}


