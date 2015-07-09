/*
 * main.cpp
 *
 */

#include "graph/in-memory/InMemoryReactiveNode.h"
#include "graph/in-memory/InMemoryReactiveEdge.h"

using namespace reactive::graph;

int main(int argc, const char* argv[]) {
	uri friendPredicate {"graph:predicates/friend"};

  InMemoryReactiveNode savas("graph:people/savas"), jim("graph:people/jim");
  InMemoryReactiveEdge frnd("graph:ids/savas-friends-jim");
  frnd.setSource(savas.getId().get()).wait();
  frnd.setPredicate(friendPredicate).wait();
  frnd.setDestination(jim.getId().get()).wait();

  savas.addOutgoingEdge(frnd.getId().get()).wait();

  return 0;
}


