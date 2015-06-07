#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class ExpensiveToCopy {
 public:
  ExpensiveToCopy() { log("constructor"); }
  ~ExpensiveToCopy() { 
    log("destructor"); 
    evolution = 0; 
  }
  
  ExpensiveToCopy(const ExpensiveToCopy& etc): msgs(etc.msgs), evolution(floor(etc.evolution + 1)) { 
    log("copy constructor (expensive)"); 
  }
  ExpensiveToCopy& operator=(const ExpensiveToCopy& rhs) { 
    msgs = rhs.msgs;
    evolution = floor(rhs.evolution + 1);
    log("copy operator="); 
    return *this; 
  }
  
  ExpensiveToCopy(ExpensiveToCopy&& etc) noexcept: msgs(move(etc.msgs)), evolution(etc.evolution + 0.1) { 
    log("move constructor (cheap)"); 
  }
  ExpensiveToCopy& operator=(ExpensiveToCopy&& rhs) { 
    msgs = move(rhs.msgs); 
    evolution = rhs.evolution + 0.1;
    log("move operator=");
    return *this; 
  }
  
  void print() const {
    log("contains " + to_string(msgs.size()) + " messages");
  }
 private:
  float evolution = 1.0;
  vector<string> msgs {
    "hello",
    "world",
  };
  
  void log(const string& str) const {
    cout << "ExpensiveToCopy (" << fixed << setprecision(1) << evolution << "): " << str << endl; 
  }
};

