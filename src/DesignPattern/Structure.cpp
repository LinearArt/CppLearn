//
//  Structure.cpp
//  CppLearn
//
//  Created by 何皓源 on 2021/10/31.
//

#include "Structure.hpp"

void testAdapter() {
  VideoPlayer vp;
  vp.play("mp4", "0.mp4");
  vp.play("mov", "1.mov");
  vp.play("mkv", "2.mkv");
  vp.play("unknown", "3.unknown");
}

void testBridge() {
  Pen* rp = new RedPen();
  Pen* gp = new GreenPen();
  BridgeCircle rc(1, rp);
  BridgeCircle gc(2, gp);
  rc.draw();
  gc.draw();
  delete rp;
  delete gp;
}

void testFilter() {
  Person mt(Person::GenderType::male, true);
  Person mf(Person::GenderType::male, false);
  Person ft(Person::GenderType::female, true);
  Person ff(Person::GenderType::female, false);
  vector<Person> pv = {mt, mf, ft, ff};
  Filter* maleF = new MaleFilter();
  Filter* singleF = new SingleFilter();
  Filter* singleMaleF = new AndFilter(maleF, singleF);
  vector<Person> fv = singleMaleF->find(pv);
  cout << "List of Single Male:\n";
  for (auto& person : fv) {
    person.display();
  }
  delete maleF;
  delete singleF;
  delete singleMaleF;
}

void testComposite() {
  Employee ceo("CEO");
  Employee hrl("HR Leader");
  Employee itl("IT Leader");
  hrl.add(Employee("HR A"));
  hrl.add(Employee("HR B"));
  itl.add(Employee("IT A"));
  itl.add(Employee("IT B"));
  ceo.add(hrl);
  ceo.add(itl);
  ceo.display();
}

void testDecorator() {
  Shape* rc = new Circle();
  rc = new RedDecorator(rc);
  rc->draw();
  delete rc;
}

void testFacade() {
  ShapeMaker sm;
  sm.drawCircle();
  sm.drawRect();
}

void testFlyweight() {
  FlyCircleFactory fcf;
  FlyCircle* r0 = fcf.get("Red");
  FlyCircle* r1 = fcf.get("Red");
  FlyCircle* g0 = fcf.get("Green");
  FlyCircle* g1 = fcf.get("Green");
  r0->draw();
  r1->draw();
  g0->draw();
  g1->draw();
}

void testProxy() {
  ImageProxy ip("/home/a.jpg");
  ip.display();
  ip.display();
}
