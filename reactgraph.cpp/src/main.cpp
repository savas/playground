/*
 * main.cpp
 *
 */

#include <iostream>

#include "graph/in-memory/InMemoryReactiveNode.h"
#include "graph/in-memory/InMemoryReactiveEdge.h"
#include "reactive/in-memory/InMemoryLambdaObserver.h"

#include "reactive/in-memory/InMemorySubject.h"

using namespace std;
using namespace reactive;
using namespace reactive::graph;

void testreactive() {
  InMemorySubject<int> subject;
  subject.subscribe(make_shared<InMemoryLambdaObserver<int>>(
    [](int i) { cout << i << endl; }
  ));

  subject.next(10).wait();
  subject.next(20).wait();
}

void testgraph() {
  InMemoryReactiveNode savas("graph:people/savas"), jim("graph:people/jim");
  InMemoryReactiveEdge frnd(uri("graph:ids/savas-friends-jim"));

  frnd.setSource(savas.getId().get()).wait();
  frnd.setPredicate("graph:predicates/friend").wait();
  frnd.setDestination(jim.getId().get()).wait();

  savas.subscribe(make_shared<InMemoryLambdaObserver<NodeIf>>(
    [](const NodeIf& node) { cout << node.getId().get() << endl; }
  ));

  savas.addOutgoingEdge(frnd.getId().get()).wait();
}

int main(int argc, const char* argv[]) {
  testreactive();
  testgraph();
  return 0;
}

