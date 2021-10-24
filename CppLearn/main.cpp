//
//  CppLearn.cpp
//  CppLearn
//
//  Created by 何皓源 on 2021/8/1.
//

#include "CppLearn.hpp"

int main() {
  Test t0("static_test_0");
  Test t1("static_test_1");
  Test::ver(1);
  
  std::cout << Test::ver() << '\n';
  
  return 0;
}
