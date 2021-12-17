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
  Client clt;
  Stock* s = new Stock("ASTOCK");
  Command* cb = new BuyStock(s);
  Command* cs = new SellStock(s);
  clt.recieve(cb);
  clt.recieve(cs);
  clt.execute();
  delete s;
  delete cb;
  delete cs;
}

void testInterpreter() {
  Expression* john = new SingleExp("John");
  Expression* bob = new SingleExp("Bob");
  Expression* julie = new SingleExp("Julie");
  Expression* sam = new SingleExp("Sam");
  OrExp isMale(john, bob);
  AndExp isFamily(julie, sam);
  cout << "John is Male: " << std::boolalpha << isMale.check("John") << '\n';
  cout << "Julie and Sam are Family: " << isFamily.check("Sam Julie") << '\n';
}

void testIterator() {
  StrContainer sc;
  Iterator* si = sc.iter();
  sc.push("AAA");
  sc.push("BBB");
  sc.push("CCC");
  while (!si->end()) {
    cout << si->next() << '\n';
  }
}

void testMediator() {
  
}
