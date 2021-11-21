//
//  Structure.hpp
//  CppLearn
//
//  Created by 何皓源 on 2021/10/30.
//

#ifndef Structure
#define Structure

#include "Common.hpp"

// Adapter
class Player {
public:
  virtual void play(const string& filename) = 0;
};

class MovPlayer : public Player {
public:
  void play(const string& filename) {
    cout << "MovPlayer::play(), filename = " << filename << '\n';
  }
};

class MkvPlayer : public Player {
public:
  void play(const string& filename) {
    cout << "MkvPlayer::play(), filename = " << filename << '\n';
  }
};

class VideoAdapter {
public:
  explicit VideoAdapter(const string& format) {
    if (format == "mov") {
      ptr_ = new MovPlayer();
    } else if (format == "mkv") {
      ptr_ = new MkvPlayer();
    } else {
      cout << "Fail to Construct VideoAdapter!\n";
      exit(-1);
    }
  }
  void play(const string& filename) {
    ptr_->play(filename);
  }
  
private:
  Player* ptr_;
};

class VideoPlayer {
public:
  void play(const string& format, const string& filename) {
    if (format == "mp4") {
      cout << "Mp4Player::play(), filename = " << filename << '\n';
    } else if (format == "mov" || format == "mkv") {
      VideoAdapter adapter(format);
      adapter.play(filename);
    } else {
      cout << "Unsupported format!\n";
      exit(-1);
    }
  }
};

// Bridge
class Pen {
public:
  virtual ~Pen() {}
  virtual void drawCircle(const int r) = 0;
};

class RedPen : public Pen {
public:
  void drawCircle(const int r) {
    cout << "draw a Red Circle, radix = " << r << '\n';
  }
};

class GreenPen : public Pen {
public:
  void drawCircle(const int r) {
    cout << "draw a Green Circle, radix = " << r << '\n';
  }
};

class BridgeShape {
public:
  virtual void draw() = 0;
  
protected:
  Pen* pen_;
};

class BridgeCircle : public BridgeShape {
public:
  explicit BridgeCircle(const int r, Pen* p) {
    r_ = r;
    pen_ = p;
  }
  void draw() {
    if (pen_) {
      pen_->drawCircle(r_);
    }
  }

private:
  int r_;
};

// Filter
class Person {
public:
  enum GenderType {male, female};
  explicit Person(GenderType g, bool m) {
    gender_ = g;
    married_ = m;
  }
  GenderType gender() {
    return gender_;
  }
  bool married() {
    return married_;
  }
  void display() {
    cout << "Gender = ";
    if (gender_ == Person::GenderType::male) {
      cout << "Male, ";
    } else {
      cout << "Female, ";
    }
    cout << "Married = ";
    if (married_) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  
private:
  GenderType gender_;
  bool married_;
};

class Filter {
public:
  virtual ~Filter() {};
  virtual vector<Person> find(vector<Person>& pv) = 0;
};

class MaleFilter : public Filter {
public:
  vector<Person> find(vector<Person>& pv) {
    vector<Person> result;
    for (auto& person : pv) {
      if (person.gender() == Person::GenderType::male) {
        result.push_back(person);
      }
    }
    return result;
  }
};

class SingleFilter : public Filter {
public:
  vector<Person> find(vector<Person>& pv) {
    vector<Person> result;
    for (auto& person : pv) {
      if (!person.married()) {
        result.push_back(person);
      }
    }
    return result;
  }
};

class AndFilter : public Filter {
public:
  AndFilter() {
    opA_ = nullptr;
    opB_ = nullptr;
  }
  explicit AndFilter(Filter* opA, Filter* opB) {
    opA_ = opA;
    opB_ = opB;
  }
  vector<Person> find(vector<Person>& pv) {
    vector<Person> result;
    if (opA_ && opB_) {
      vector<Person> tmp = opB_->find(pv);
      result = opA_->find(tmp);
    }
    return result;
  }
  
private:
  Filter* opA_;
  Filter* opB_;
};

// Composite
class Employee {
public:
  explicit Employee(const string title) {
    title_ = title;
  }
  void add(Employee p) {
    sub_.push_back(p);
  }
  void display() {
    cout << title_ << '\n';
    if (!(sub_.empty())) {
      for (auto& p : sub_) {
        p.display();
      }
    }
  }
  
private:
  string title_;
  vector<Employee> sub_;
};

// Decorator
class Shape {
public:
  virtual ~Shape() {}
  virtual void draw() = 0;
};

class Circle : public Shape {
public:
  void draw() {
    cout << "Circle::draw()\n";
  }
};

class Decorator : public Shape {
public:
  virtual void set() = 0;
  
protected:
  Shape* shape_;
};

class RedDecorator : public Decorator {
public:
  explicit RedDecorator(Shape* shape) {
    shape_ = shape;
  }
  ~RedDecorator() {
    if (shape_) {
      delete shape_;
    }
  }
  void draw() {
    set();
    if (shape_) {
      shape_->draw();
    }
  }
  void set() {
    cout << "Set Red Color\n";
  }
};

// Facade
class Rectangle : public Shape {
public:
  void draw() {
    cout << "Rectangle::draw()\n";
  }
};

class ShapeMaker {
public:
  void drawCircle() {
    circle_.draw();
  }
  void drawRect() {
    rect_.draw();
  }
  
private:
  Circle circle_;
  Rectangle rect_;
};

// Flyweight

#endif /* Structure */
