//
//  Effective.hpp
//  Effective
//
//  Created by 何皓源 on 2021/8/1.
//

#ifndef Effective
#define Effective

#include "Common.hpp"

class Test {
public:
  explicit Test(const string& rhs) {
    str_ = rhs;
  }
  const char& operator[] (int pos) const {
    cout << "call const []!\n";
    return str_[pos];
  }
  char& operator[] (int pos) {
    cout << "call non-const []!\n";
    return str_[pos];
  }
  static int ver() {
    return ver_;
  }
  static void ver(int v) {
    ver_ = v;
  }
  
private:
  string str_;
  static int ver_;
};

int Test::ver_ = 0;

#endif /* EffectiveCpp */
