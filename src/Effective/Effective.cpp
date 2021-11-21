//
//  Effective.cpp
//  CppLearn
//
//  Created by 何皓源 on 2021/10/31.
//

#include "Effective.hpp"

void testEffective() {
  Test t0("static_test_0");
  Test t1("static_test_1");
  Test::ver(1);
  cout << Test::ver() << '\n';
}
