//
//  Behavior.cpp
//  CppLearn
//
//  Created by 何皓源 on 2021/11/27.
//

#include "Behavior.hpp"

void testCOR() {
  Log* info = new InfoLog(Log::ltype::INFO);
  Log* error = new ErrorLog(Log::ltype::ERROR);
  error->set(info);
  error->log(Log::ltype::ERROR, "Something is Error");
  error->log(Log::ltype::INFO, "Something is INFO");
  delete info;
  delete error;
}

void testCommand() {
  
}
