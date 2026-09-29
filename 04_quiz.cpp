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

void quiz_51() {
    Product product("Keyboard", 30000, 5);
    product.sell(2);
    product.addStock(1);
    if (!product.sell(10))
        cout << "판매 실패" << '\n';
    cout << product.getStock();
}

int main() {
    quiz_51();
    return 0;
}