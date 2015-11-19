#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;

void log(string msg) {
  cout << msg << endl;
}

class A {
public:
  A() = default;
  ~A() { log("A destructor!"); }
};

class B: public A {
public:
  B() = default;
  ~B() { log("B destructor!"); }
};

int main(int argc, char* argv[]) {
	char buf[4] = {'a', 'b', 'c', 'd'};
  shared_ptr<A> b;
  b.reset(new B());
}