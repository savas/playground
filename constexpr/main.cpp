#include "Foo.h"
#include <iostream>
#include <utility>

using namespace std;

int main(int argc, char* argv[]) {
  Foo foo;
  
  // Works great
  cout << Foo::foo << endl;
  
  // Doesn't work
  //pair<string, string> p = {Foo::foo, "hello"};
  
  // Works
  string s = Foo::foo;
  pair<string, string> p = {s, "hello"};
}