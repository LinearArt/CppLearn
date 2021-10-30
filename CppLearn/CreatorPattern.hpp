//
//  CreatorPattern.hpp
//  CppLearn
//
//  Created by 何皓源 on 2021/10/30.
//

#ifndef CreatorPattern
#define CreatorPattern

#include "Common.hpp"

// Factory & Abstract Factory
class Shape {
public:
  virtual ~Shape() {};
  virtual void draw() = 0;
};

class Rectangle: public Shape {
public:
  void draw() {
    cout << "Rectangle::draw()\n";
  }
};

class Circle: public Shape {
public:
  void draw() {
    cout << "Circle::draw()\n";
  }
};

class Color {
public:
  virtual ~Color() {}
  virtual void fill() {};
};

class Red: public Color {
public:
  void fill() {
    cout << "Red::fill()\n";
  }
};

class Green: public Color {
public:
  void fill() {
    cout << "Green::fill()\n";
  }
};

class ShapeFactory {
public:
  Shape* getShape(const string& type) {
    if (type == "Rectangle") {
      return new Rectangle();
    } else if (type == "Circle") {
      return new Circle();
    }
    return nullptr;
  }
};

class AbsFactory {
public:
  virtual ~AbsFactory() {}
  virtual Shape* getShape(const string& type) = 0;
  virtual Color* getColor(const string& type) = 0;
};

class AbsShapeFactory: public AbsFactory {
public:
  Shape* getShape(const string& type) {
    if (type == "Rectangle") {
      return new Rectangle();
    } else if (type == "Circle") {
      return new Circle();
    }
    return nullptr;
  }
  Color* getColor(const string& type) {
    return nullptr;
  }
};

class AbsColorFactory: public AbsFactory {
public:
  Color* getColor(const string& type) {
    if (type == "Red") {
      return new Red();
    } else if (type == "Green") {
      return new Green();
    }
    return nullptr;
  }
  Shape* getShape(const string& type) {
    return nullptr;
  }
};

class AbsFactoryProducer {
public:
  AbsFactory* getFactory(const string& type) {
    if (type == "Shape") {
      return new AbsShapeFactory();
    } else if (type == "Color") {
      return new AbsColorFactory();
    }
    return nullptr;
  }
};

// Singleton
class Single {
public:
  static Single get() {
    return obj_;
  }
  void display() {
    cout << "I'm born to be Single!\n";
  }
private:
  Single() {}
  static Single obj_;
};

// Builder
class Packing {
public:
  virtual const string type() {
    return "";
  }
};

class Bottle: public Packing {
public:
  const string type() {
    return "Bottle";
  }
};

class Wrapper: public Packing {
public:
  const string type() {
    return "Wrapper";
  }
};

class Food {
public:
  Food() {
    pack_ = nullptr;
  }
  virtual const string name() {
    return "";
  }
  virtual const float price() {
    return 0.0f;
  }
  Packing* pack() {
    return pack_;
  }

protected:
  Packing* pack_;
};

class Burger: public Food {
public:
  Burger() {
    pack_ = new Wrapper();
  }
  ~Burger() {
    delete pack_;
  }
};

class Drink: public Food {
public:
  Drink() {
    pack_ = new Bottle();
  }
  ~Drink() {
    delete pack_;
  }
};

class VegBurger: public Burger {
public:
  const string name() {
    return "Veg Burger";
  }
  const float price() {
    return 25.0f;
  }
};

class BeefBurger: public Burger {
public:
  const string name() {
    return "Beef Burger";
  }
  const float price() {
    return 50.0f;
  }
};

class Coke: public Drink {
public:
  const string name() {
    return "Coke";
  }
  const float price() {
    return 30.0f;
  }
};

class Pepsi: public Drink {
public:
  const string name() {
    return "Pepsi";
  }
  const float price() {
    return 35.0f;
  }
};

class Menu {
public:
  void add(Food* food) {
    content_.push_back(food);
  }
  const float price() {
    float sum = 0.0f;
    for (auto& food : content_) {
      sum += food->price();
    }
    return sum;
  }
  void display() {
    for (auto& food : content_) {
      cout << "Food: " << food->name() << ", "
        << "Packing: " << food->pack()->type() << ", "
        << "Price: " << food->price() << '\n';
    }
  }
  
private:
  vector<Food*> content_;
};

class MenuBuilder {
public:
  MenuBuilder() {
    vegBurger_ = new VegBurger();
    beefBurger_ = new BeefBurger();
    coke_ = new Coke();
    pepsi_ = new Pepsi();
    veg_.add(vegBurger_);
    veg_.add(coke_);
    beef_.add(beefBurger_);
    beef_.add(pepsi_);
  }
  ~MenuBuilder() {
    delete vegBurger_;
    delete beefBurger_;
    delete coke_;
    delete pepsi_;
  }
  void display() {
    veg_.display();
    beef_.display();
  }
  
private:
  Menu veg_;
  Menu beef_;
  Food* vegBurger_;
  Food* beefBurger_;
  Food* coke_;
  Food* pepsi_;
};

#endif /* CreatorPattern */
