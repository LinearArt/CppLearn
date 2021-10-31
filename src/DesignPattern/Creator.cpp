//
//  Creator.cpp
//  CppLearn
//
//  Created by 何皓源 on 2021/10/31.
//

#include "Creator.hpp"

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
