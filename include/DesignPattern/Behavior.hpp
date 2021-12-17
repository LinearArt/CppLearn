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
class Stock {
public:
  explicit Stock(const string& n) {
    name_ = n;
  }
  void buy() {
    cout << name_ << " is Bought!\n";
  }
  void sell() {
    cout << name_ << " is Sold!\n";
  }
  
private:
  string name_;
};

class Command {
public:
  virtual ~Command() {}
  virtual void execute() = 0;
};

class BuyStock : public Command {
public:
  explicit BuyStock(Stock* s) {
    stock_ = s;
  }
  void execute() {
    if (stock_) {
      stock_->buy();
    }
  }
  
private:
  Stock* stock_;
};

class SellStock : public Command {
public:
  explicit SellStock(Stock* s) {
    stock_ = s;
  }
  void execute() {
    if (stock_) {
      stock_->sell();
    }
  }
  
private:
  Stock* stock_;
};

class Client {
public:
  void recieve(Command* c) {
    cmd_.push_back(c);
  }
  void execute() {
    for (auto command : cmd_) {
      command->execute();
    }
    cmd_.clear();
  }
  
private:
  vector<Command*> cmd_;
};

// Interpreter
class Expression {
public:
  virtual ~Expression() {}
  virtual bool check(const string& s) = 0;
};

class SingleExp : public Expression {
public:
  explicit SingleExp(const string& t) {
    text_ = t;
  }
  bool check(const string& s) {
    return s.find(text_) != string::npos;
  }
  
private:
  string text_;
};

class OrExp : public Expression {
public:
  explicit OrExp(Expression* a, Expression* b) {
    opA_ = a;
    opB_ = b;
  }
  bool check(const string& s) {
    return (opA_ && opA_->check(s)) || (opB_ && opB_->check(s));
  }
  
private:
  Expression* opA_;
  Expression* opB_;
};

class AndExp : public Expression {
public:
  explicit AndExp(Expression* a, Expression* b) {
    opA_ = a;
    opB_ = b;
  }
  bool check(const string& s) {
    return (opA_ && opA_->check(s)) && (opB_ && opB_->check(s));
  }
  
private:
  Expression* opA_;
  Expression* opB_;
};

// Iterator
class Iterator {
public:
  virtual ~Iterator() {}
  virtual string& next() = 0;
  virtual bool end() = 0;
};

class Container {
public:
  virtual void push(const string& s) = 0;
  virtual const size_t size() = 0;
  virtual string& get(const size_t i) = 0;
  virtual Iterator* iter() = 0;
};

class StrIterator : public Iterator {
public:
  explicit StrIterator(Container* obj):
    idx_(0),
    obj_(obj) {}
  string& next() {
    if (!this->end()) {
      return obj_->get(idx_++);
    }
    return obj_->get(0);
  }
  bool end() {
    return idx_ == obj_->size();
  }
  
private:
  size_t idx_;
  Container* obj_;
};

class StrContainer : public Container {
public:
  StrContainer():
    cache_(),
    iter_(nullptr) {}
  ~StrContainer() {
    if (iter_) {
      delete iter_;
    }
  }
  void push(const string& s) {
    cache_.push_back(s);
  }
  const size_t size() {
    return cache_.size();
  }
  string& get(const size_t i) {
    return cache_[i];
  }
  Iterator* iter() {
    if (!iter_) {
      iter_ = new StrIterator(this);
    }
    return iter_;
  }
  
private:
  vector<string> cache_;
  Iterator* iter_;
};

// Mediator

#endif /* Behavior */
