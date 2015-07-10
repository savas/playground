/*
 * main.cpp
 *
 */

#include "graph/in-memory/InMemoryReactiveNode.h"
#include "graph/in-memory/InMemoryReactiveEdge.h"

#include "reactive/in-memory/InMemorySubject.h"

using namespace reactive;
using namespace reactive::graph;

int main(int argc, const char* argv[]) {
  InMemorySubject<int> subject;

  subject.next(10);

	uri friendPredicate {"graph:predicates/friend"};

  InMemoryReactiveNode savas(uri("graph:people/savas")), jim(uri("graph:people/jim"));
  InMemoryReactiveEdge frnd(uri("graph:ids/savas-friends-jim"));
  frnd.setSource(savas.getId().get()).wait();
  frnd.setPredicate(friendPredicate).wait();
  frnd.setDestination(jim.getId().get()).wait();

  savas.addOutgoingEdge(frnd.getId().get()).wait();

  return 0;
}


