//
//  Behavior.hpp
//  CppLearn
//
//  Created by 何皓源 on 2021/11/27.
//

#ifndef Behavior
#define Behavior

#include "Common.hpp"

// Chain of Responsibility
class Log {
public:
  virtual ~Log() {}
  enum ltype {INFO, ERROR};
  void set(Log* next) {
    next_ = next;
  }
  void log(ltype level, const string& msg) {
    if (level_ == level) {
      write(msg);
    } else if (next_) {
      next_->log(level, msg);
    }
  }
  
protected:
  virtual void write(const string& msg) = 0;
  ltype level_;
  Log* next_;
};

class InfoLog : public Log {
public:
  explicit InfoLog(ltype level) {
    level_ = level;
    next_ = nullptr;
  }
  
protected:
  void write(const string& msg) override {
    cout << "Info: " << msg << '\n';
  }
};

class ErrorLog : public Log {
public:
  explicit ErrorLog(ltype level) {
    level_ = level;
    next_ = nullptr;
  }
  
protected:
  void write(const string& msg) override {
    cout << "Error: " << msg << '\n';
  }
};

// Command

#endif /* Behavior */
