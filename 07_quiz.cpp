#include <iostream>
#include <string>

using namespace std;

void quiz_46() {}

class Point {
   private:
    int x;
    int y;

   public:
    Point(int x, int y) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    void print() const {
        cout << "(" << x << "," << y << ")" << '\n';
    }
};

Point addPoint(const Point& p1, const Point& p2) {
    return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
}

void quiz_47() {
    Point p1(10, 20);
    Point p2(3, 5);
    Point result = addPoint(p1, p2);
    p1.print();
    p2.print();
    result.print();
}

class ScoreList {
    int* scores;
    int size;

   public:
    ScoreList(int size) : size{size} {
        scores = new int[size];
    }
    ScoreList(const ScoreList& s) : size{s.size}, scores{new int[s.size]} {
        for (int i = 0; i < size; i++) scores[i] = s.scores[i];
    }
    void setScore(int i, int score) {
        scores[i] = score;
    }
    int getScore(int i) const {
        return scores[i];
    }
    ~ScoreList() {
        delete[] scores;
        scores = nullptr;
    }
};

void quiz_48() {
    ScoreList original(3);
    original.setScore(0, 70);
    original.setScore(1, 80);
    original.setScore(2, 90);
    ScoreList copy = original;
    copy.setScore(0, 100);
    cout << original.getScore(0) << '\n';
    cout << copy.getScore(0) << '\n';
    cout << copy.getScore(1) << '\n';
    cout << copy.getScore(2);
}

class Message {
    string text;

   public:
    Message(string t) : text{t} {}
    string getText() const {
        return text;
    }
};

void process(Message& m) {
    cout << "saved : " << m.getText() << endl;
}

void process(Message&& m) {
    cout << "temporary : " << m.getText() << endl;
}

void quiz_49() {
    Message saved("Hello");
    process(saved);
    process(Message("Welcome"));
    process(move(saved));
}

class Buffer {
    int* data;
    int size;

   public:
    Buffer(int s) : size{s}, data{new int[size]} {}
    Buffer(const Buffer& bf) : size{bf.size}, data{new int[bf.size]} {
        for (int i = 0; i < size; i++) {
            data[i] = bf.data[i];
        }
    }
    Buffer(Buffer&& bf) noexcept : size{bf.size}, data{bf.data} {
        bf.data = nullptr;
        bf.size = 0;
    }
    ~Buffer() {
        delete[] data;
        data = nullptr;
    }
    void set(int i, int v) {
        data[i] = v;
    }
    int get(int i) const {
        return data[i];
    }
};

void quiz_50() {
    Buffer original(3);
    original.set(0, 10);
    original.set(1, 20);
    original.set(2, 30);
    Buffer copied(original);
    copied.set(0, 100);
    Buffer moved(move(original));
    cout << copied.get(0) << '\n';
    cout << moved.get(0) << ' ';
    cout << moved.get(1) << ' ';
    cout << moved.get(2);
}

void quiz_51();  // 객체 내부에 동적할당된 멤버가 있을때 복사 이후에 메모리 공유 문제가 발생할 수 있음

void quiz_52() {}

class Bus {
    int* id;

   public:
    Bus() : Bus(0) {}
    Bus(int i) : id{new int{i}} {}
    Bus(const Bus& b);
    ~Bus() {
        delete id;
        id = nullptr;
    }
};

Bus::Bus(const Bus& b) : id{new int{*(b.id)}} {}

void quiz_53();  // Bus class

class Person {
    string* name;
    int age;

   public:
    Person() : Person("anonymous", 21) {}
    Person(string n, int a) : name{new string{n}}, age{a} {}
    Person(Person&& p) noexcept;
    ~Person() {
        delete name;
        name = nullptr;
    }
};

Person::Person(Person&& p) noexcept : name{p.name}, age{p.age} {
    p.name = nullptr;
    p.age = 0;
}

void quiz_54();  // Person class

void quiz_55() {}

int main() {
    quiz_50();
}