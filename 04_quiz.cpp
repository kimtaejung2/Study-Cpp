#include <iostream>
#include <string>

#include "Product.h"

using namespace std;

class Rectangle {
   private:
    int width;
    int height;

   public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int getArea() const {
        return width * height;
    }
};

void quiz_46() {
    Rectangle r1(4, 5);
    Rectangle r2(3, 7);
    cout << r1.getArea() << '\n';
    cout << r2.getArea();
}

class Account {
   private:
    string owner;
    int balance;

   public:
    Account(string o, int b) : owner(o), balance(b) {}
    void deposit(int b);
    bool withdraw(int m);
    string getOwner() const;
    int getBalance() const;
};

void Account::deposit(int m) {
    balance += m;
}

bool Account::withdraw(int m) {
    if (m < balance) {
        balance -= m;
        return true;
    }
    return false;
}

string Account::getOwner() const {
    return owner;
}

int Account::getBalance() const {
    return balance;
}

void quiz_47() {
    Account account("Kim", 10000);
    account.deposit(5000);
    if (!account.withdraw(20000))
        cout << "출금 실패" << '\n';
    account.withdraw(3000);
    cout << account.getOwner() << '\n';
    cout << account.getBalance();
}

class Box {
   private:
    int width;
    int height;
    int depth;

   public:
    Box(int w, int h, int d) : width(w), height(h), depth(d) { cout << "Box 생성" << endl; }
    Box() : Box(1, 1, 1) {}
    ~Box() { cout << endl
                  << "Box 소멸" << endl; }
    int getVolume() const {
        return width * height * depth;
    }
};

void quiz_48() {
    Box b1;
    Box b2(2, 3, 4);

    cout << b1.getVolume() << endl;
    cout << b2.getVolume();
}

class Battery {
   private:
    int capacity;

   public:
    Battery() = delete;
    Battery(int c) : capacity(c) {
        cout << "Battery 생성" << endl;
    }
    ~Battery() { cout << "Battery 소멸" << endl; }
};

class Device {
   private:
    string name;
    Battery bat;

   public:
    Device() = delete;
    Device(string n, int c) : name(n), bat(c) {
        cout << "Device 생성" << endl;
    }
    ~Device() { cout << "Device 소멸" << endl; }
};

void quiz_49() {
    Device phone("Phone", 5000);
}

class Book {
   private:
    string title;
    bool borrowed;

   public:
    Book(string t, bool b) : title(t), borrowed(b) {}
    Book(string t) : Book(t, false) {}
    bool borrow() {
        if (!borrowed) {
            borrowed = true;
            return true;
        }
        return false;
    }
    bool returnBook() {
        if (borrowed) {
            borrowed = false;
            return true;
        }
        return false;
    }
    void print() const {
        cout << title << ":";
        if (borrowed)
            cout << "대출 중" << endl;

        else
            cout << "대충 가능" << endl;
    }
};

void quiz_50() {
    Book book("C++ Programming");
    if (book.borrow())
        cout << "대출 성공" << endl;
    if (!book.borrow())
        cout << "대출 실패" << endl;
    book.print();
    book.returnBook();
    book.print();
}

void quiz_51();  // Product.h Product.cpp Product_main.cpp

class Sample {
   public:
    int number;
};

void quiz_52();  // Sample class

class Car {
   private:
    string color;
    int maxSpeed;

   public:
    Car();
    Car(string c, int ms);
};

Car::Car() : Car("Black", 200) {};
Car::Car(string c, int ms) : color{c}, maxSpeed{ms} {}
void quiz_53() {
    Car obj1("Red", 100);
}

class Circle {
   private:
    int radius;
    double PI = 3.14;

   public:
    Circle(int r);
    double getArea() const {}
};

Circle::Circle(int r) : radius{r} {}
double Circle::getArea() const {
    return radius * radius * PI;
}

void quiz_54();  // Circle class

class Student {
   private:
    string name;
    int id;

   public:
    Student(string name, int id);
};

Student::Student(string name, int id) : name{name}, id{id} {}

void quiz_55();  // Student class

class Triangle {
   private:
    int base;
    int height;

   public:
    Triangle(int b, int h);
    ~Triangle();
};

Triangle::Triangle(int b, int h) : base{b}, height{h} {}

void quiz_56();  // Triangle class

int main() {
    quiz_50();
    return 0;
}