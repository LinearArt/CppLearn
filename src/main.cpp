//
//  CppLearn.cpp
//  CppLearn
//
//  Created by 何皓源 on 2021/8/1.
//

#include "EffectiveCpp.hpp"
#include "Creator.hpp"
#include "Structure.hpp"

void testEffectiveCpp() {
  Test t0("static_test_0");
  Test t1("static_test_1");
  Test::ver(1);
  cout << Test::ver() << '\n';
}

void testFactory() {
  ShapeFactory* sf = new ShapeFactory();
  Shape* rect = sf->getShape("Rectangle");
  Shape* circle = sf->getShape("Circle");
  rect->draw();
  circle->draw();
  delete rect;
  delete circle;
  delete sf;
}

void testAbsFactory() {
  AbsFactoryProducer* fp = new AbsFactoryProducer();
  AbsFactory* sf = fp->getFactory("Shape");
  AbsFactory* cf = fp->getFactory("Color");
  Shape* rect = sf->getShape("Rectangle");
  Shape* circle = sf->getShape("Circle");
  Color* red = cf->getColor("Red");
  Color* green = cf->getColor("Green");
  rect->draw();
  circle->draw();
  red->fill();
  green->fill();
  delete rect;
  delete circle;
  delete sf;
  delete red;
  delete green;
  delete cf;
  delete fp;
}

void testSingle() {
  Single::get().display();
}

void testBuilder() {
  MenuBuilder mb;
  mb.display();
}

void testProtoType() {
  CloneShapeCache sc;
  CloneShape* rect = sc.get(1);
  CloneShape* circle = sc.get(2);
  if (rect) {
    rect->draw();
    delete rect;
  }
  if (circle) {
    circle->draw();
    delete circle;
  }
}

int main() {
  testProtoType();
  
  return 0;
}