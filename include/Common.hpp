//
//  Common.hpp
//  CppLearn
//
//  Created by 何皓源 on 2021/10/30.
//

#ifndef Common
#define Common

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::cout;
using std::string;
using std::vector;
using std::unordered_map;

// test Effective
void testEffective();

// test Creator
void testFactory();
void testAbsFactory();
void testSingle();
void testBuilder();
void testProtoType();

// test Structure
void testAdapter();
void testBridge();
void testFilter();
void testComposite();
void testDecorator();
void testFacade();
void testFlyweight();
void testProxy();

// test Behavior
void testCOR();
void testCommand();
void testInterpreter();
void testIterator();
void testMediator();

#endif /* Common */
