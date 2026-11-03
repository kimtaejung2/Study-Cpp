#include <iostream>
#include <string>

using namespace std;

void quiz_40();  // 1. 이름 일치 2. 매개변수 불일치

int add(int a, int b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

void quiz_41() {
    cout << add(1, 2) << endl;
    cout << add(1, 2, 3) << endl;
}

class Person {
    int age;
    string name;

   public:
    Person(int a = 22, string n = "Alice") : age{a}, name{n} {
        cout << age << ", " << name << endl;
    }
};

void quiz_42() {
    Person(21, "Kim");
    Person();
}

class BankAccount {
    int money;

   public:
    static int sharedMoney;
    BankAccount(int m) : money{m} {}
};

int BankAccount::sharedMoney = 100;

void quiz_43() {
    cout << BankAccount::sharedMoney;
}

class Color {
   public:
    inline static string color = "#FF0000";
    static void changeColor(string c) {
        color = c;
    }
};

void quiz_44() {
    Color c1;
    c1.changeColor("#0F15D3");
    Color::changeColor("#56F1A2");

    cout << c1.color << endl;
}

class Printer {
   public:
    void print(int value) {
        cout << "int : " << value << endl;
    }
    void print(double value) {
        cout << "double : " << value << endl;
    }
    void print(string value) {
        cout << "string : " << value << endl;
    }
};

void quiz_45() {
    Printer printer;
    printer.print(10);
    printer.print(3.5);
    printer.print("Hello");
}

static void drawLine(int n = 10, char ch = '*') {
    for (int i = 0; i < n; i++) cout << ch;
    cout << endl;
}

void quiz_46() {
    drawLine();
    drawLine(5);
    drawLine(3, '#');
}

class Student {
    string name;
    static int count;

   public:
    Student(string n) : name{n} {
        count += 1;
    }
    ~Student() {
        count -= 1;
    }
    static int getCount() {
        return count;
    }
};

int Student::count = 0;

void quiz_47() {
    cout << Student::getCount() << '\n';
    Student s1("Kim");
    {
        Student s2("Lee");
        Student s3("Park");
        cout << Student::getCount() << '\n';
    }
    cout << Student::getCount();
}

class BankAccount2 {
    int balance;
    static int totalBalance;

   public:
    BankAccount2(int b) : balance{b} {
        totalBalance += balance;
    }
    void deposit(int amount) {
        balance += amount;
        totalBalance += amount;
    }
    int getBalance() {
        return balance;
    }
    static int getTotalBalance() {
        return totalBalance;
    }
};

int BankAccount2::totalBalance = 0;

void quiz_48() {
    BankAccount2 a(1000);
    BankAccount2 b(2000);
    a.deposit(500);
    b.deposit(1000);
    cout << a.getBalance() << '\n';
    cout << b.getBalance() << '\n';
    cout << BankAccount2::getTotalBalance();
}

class Product {
    string name;
    int price;

   public:
    Product(string name, int price) : name{name}, price{price} {}
    string getName() const {
        return name;
    }
    int getPrice() const {
        return price;
    }
    void print() {
        cout << "normal : " << name << ", " << price << endl;
    }
    void print() const {
        cout << "const : " << name << ", " << price << endl;
    }
    ~Product() {}
};

void quiz_49() {
    Product p1("Keyboard", 50000);
    const Product p2("Mouse", 30000);
    p1.print();
    p2.print();
}

int main() {
    quiz_49();
}