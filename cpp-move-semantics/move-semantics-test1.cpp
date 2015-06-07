// Nothing better than some code to learn a new feature :-)
// Compile on MacOS: clang++ -std=c++14 <filename>.cpp

#include "ExpensiveToCopy.h"

// Copy constuctor called.
auto func1() {
  ExpensiveToCopy expensiveToCopy;
  return [etc = expensiveToCopy] { etc.print(); };
}

// Don't do this! You are lucky if this worked as expected or the
// process didn't crash.
auto func2() {
  ExpensiveToCopy expensiveToCopy;
  return [&etc = expensiveToCopy] { etc.print(); };
}

// Best approach for objects that are expensive to copy.
auto func3() {
  ExpensiveToCopy expensiveToCopy;
  return  [etc = move(expensiveToCopy)] { etc.print(); };
}

// One might be tempted to apply move semantics when
// returning a value. Don't!!! Compilers can optimize this.
ExpensiveToCopy func4() {
  ExpensiveToCopy expensiveToCopy;
  return move(expensiveToCopy); 
}

// No copy/move operations taking place. NRVO optimization.
ExpensiveToCopy func5() {
  ExpensiveToCopy expensiveToCopy;
  return expensiveToCopy;
}

// No copy/move operations taking place. RVO optimization.
ExpensiveToCopy func6() {
  return ExpensiveToCopy(); 
}

int main() {
  {
    cout << "Get lambda with value capture" << endl;
    auto f = func1();
    cout << "Call lambda" << endl;
    f(); 
  }
  cout << endl;
  
  {
    // If this works with your compiler, you just got lucky!
    cout << "Get lambda with reference capture" << endl;
    auto f = func2();
    cout << "Call lambda" << endl;
    f();
  }
  cout << endl;
  
  {  
    cout << "Get lambda with rvalue" << endl;
    auto f = func3();
    cout << "Call lambda" << endl;
    f();
  }
  cout << endl;
   
  {  
    cout << "Return object with move" << endl;
    auto f = func4();
  }
  cout << endl;

  {  
    cout << "Return object without move. Name return value optimization by compiler." << endl;
    auto f = func5();
  }
  cout << endl;

  {  
    cout << "Return object without move. Return value optimization by compiler." << endl;
    auto f = func6();
  }
  cout << endl;
}