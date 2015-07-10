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
  InMemoryLambdaObserver<int> observer { [](int i) { cout << i << endl; }};
  subject.subscribe(make_shared<InMemoryLambdaObserver<int>>(move(observer)));

  subject.next(10).wait();
  subject.next(20).wait();
}

void testgraph() {
  uri friendPredicate {"graph:predicates/friend"};

  InMemoryReactiveNode savas(uri("graph:people/savas")), jim(uri("graph:people/jim"));
  InMemoryReactiveEdge frnd(uri("graph:ids/savas-friends-jim"));
  frnd.setSource(savas.getId().get()).wait();
  frnd.setPredicate(friendPredicate).wait();
  frnd.setDestination(jim.getId().get()).wait();

  InMemoryLambdaObserver<NodeIf> observer { [](const NodeIf& node) { cout << node.getId().get() << endl; }};
  savas.subscribe(make_shared<InMemoryLambdaObserver<NodeIf>>(observer));

  savas.addOutgoingEdge(frnd.getId().get()).wait();
}

int main(int argc, const char* argv[]) {
  testreactive();
  testgraph();
  return 0;
}

