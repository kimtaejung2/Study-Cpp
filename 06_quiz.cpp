#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Device {
   private:
    string name;

   public:
    Device(string name) : name(name) {}
    void print() const {
        cout << name << endl;
    }
};

void useDevice(shared_ptr<Device> device) {
    device->print();
    cout << device.use_count() << endl;
}

void quiz_21() {
    unique_ptr<Device> p = make_unique<Device>("Monitor");
    useDevice(move(p));
    if (!p) cout << "소유권 없음" << endl;
}

void quiz_22() {
    shared_ptr<Device> p1 = make_shared<Device>("Printer");
    shared_ptr<Device> p2 = p1;

    cout << p1.use_count() << endl;
    useDevice(p1);
    p2 = nullptr;  // p2.reset() or p2가 사용되는 부분을 내부함수{}로 묶음.
    cout << p1.use_count() << endl;
}

class Book {
   private:
    string name;
    int id;

   public:
    Book(string n, int i) {
        cout << "생성" << endl;
    };
    ~Book() { cout << "소멸" << endl; };
};

void quiz_23() {
    unique_ptr<Book> p = make_unique<Book>("kim", 20235150);
}

class Person {
    unique_ptr<string> name;

   public:
    weak_ptr<Person> per;
    Person();
    Person(string n);
    ~Person() {}
};

Person::Person() : Person("Sample") {}
Person::Person(string n) : name{make_unique<string>(n)} {}

void quiz_24() {
    auto p1 = make_shared<Person>();
    auto p2 = make_shared<Person>();

    p1->per = p2;
    p2->per = p1;

    cout << p1.use_count() << endl;
    cout << p2.use_count();
}

class Apple {
   public:
    Apple() { cout << "yummy apple" << endl; }
    ~Apple() { cout << "finished apple" << endl; }
};

void quiz_25() {
    vector<Apple> v(3);
}

int main() {
    quiz_22();
    return 0;
}