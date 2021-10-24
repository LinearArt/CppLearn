//
//  CppLearn.hpp
//  CppLearn
//
//  Created by 何皓源 on 2021/8/1.
//

#ifndef CppLearn_hpp
#define CppLearn_hpp

#include <iostream>

class Test {
public:
  Test() {
    len_ = 0;
    str_ = NULL;
  }
  explicit Test(const char* rhs) {
    len_ = std::strlen(rhs);
    str_ = new char[len_];
    std::strcpy(str_, rhs);
  }
  ~Test() {
    if (str_) {
      delete[] str_;
    }
  }
  const char& operator[] (int pos) const {
    std::cout << "call const []!\n";
    return str_[pos];
  }
  char& operator[] (int pos) {
    std::cout << "call non-const []!\n";
    return str_[pos];
  }
  static int ver() {
    return ver_;
  }
  static void ver(int v) {
    ver_ = v;
  }
  
private:
  char* str_;
  size_t len_;
  static int ver_;
};

int Test::ver_ = 0;

#endif /* CppLearn_hpp */
