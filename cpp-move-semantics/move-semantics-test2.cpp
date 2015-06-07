// Nothing better than some code to learn a new feature :-)
// Compile on MacOS: clang++ -std=c++14 <filename>.cpp

#include "ExpensiveToCopy.h"

class KeepsEtcRef {
 public:
  KeepsEtcRef() = delete;
  KeepsEtcRef(ExpensiveToCopy& etcArg): etc(etcArg) { cout << "KeepsEtcRef: costructor" << endl; }
  ~KeepsEtcRef() { cout << "KeepsEtcRef: destructor" << endl; } 
  void print() { etc.print(); } 
 private:
  ExpensiveToCopy& etc;
};

class KeepsEtc {
 public:
  KeepsEtc() = delete;
  KeepsEtc(ExpensiveToCopy&& etc): large(move(etc)) { cout << "KeepsEtc: costructor" << endl; }
  ~KeepsEtc() { cout << "KeepsEtc: destructor" << endl; }
  void print() { large.print(); } 
 private:
  ExpensiveToCopy large;
};

int main() {  
  {
    cout << "KeepsEtcRef" << endl;
    ExpensiveToCopy etc;
    KeepsEtcRef k(etc);
    k.print();
  }
  cout << endl;

  {
    cout << "KeepEtcRef outlives ExpensiveToCopy" << endl;
    ExpensiveToCopy* etc = new ExpensiveToCopy();
    KeepsEtcRef k(*etc);
    delete etc;
    k.print();
  }
  cout << endl;
  
  {
    cout << "KeepsEtc" << endl;
    ExpensiveToCopy etc;
    KeepsEtc k(move(etc));
    k.print();
  }
  cout << endl;

  {
    cout << "KeepsEtc outlives ExpensiveToCopy" << endl;
    ExpensiveToCopy* etc = new ExpensiveToCopy();
    KeepsEtc kl(move(*etc));
    delete etc;
    kl.print();
  }
  cout << endl;

  {
    cout << "Call to etc after it was moved" << endl;
    ExpensiveToCopy etc;
    KeepsEtc kl(move(etc));
    etc.print();
  }
  cout << endl;
}