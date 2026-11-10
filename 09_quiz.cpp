#include <iostream>
#include <string>

using namespace std;

class Manager {
};

class Event {
   public:
    friend Manager;
};

void quiz_28();

class Point {
    int x, y;

   public:
    Point(int x = 0, int y = 0) : x{x}, y{y} {}

    Point operator+(const Point& p) {
        return Point(this->x + p.x, this->y + p.y);
    }

    void operator+=(const Point& p) {
        this->x += p.x;
        this->y += p.y;
    }

    Point& operator=(const Point& p) {
        if (this == &p) return *this;
        this->x = p.x;
        this->y = p.y;
        return *this;
    }

    bool operator==(const Point& p) {
        return (this->x == p.x) && (this->y == p.y);
    }

    void print() {
        cout << "x = " << this->x << ", y = " << this->y << endl;
    }
};

void quiz_29() {
    Point c = Point(3, 5);
    Point d = Point(2, 4);
    Point e = c + d;
    e.print();
}

void quiz_30() {
    Point* a = new Point(3, 5);
    Point* b = new Point(2, 4);

    *a += *b;
    a->print();

    delete a;
    delete b;
}

void quiz_31() {
    Point* a = new Point(3, 4);
    Point* b = new Point(2, 4);

    *a = *b;
    a->print();

    delete a;
    delete b;
}

void quiz_32() {
    Point* a = new Point(2, 4);
    Point* b = new Point(2, 4);
    Point c = Point(3, 4);
    Point d = Point(2, 4);

    if (*a == *b)
        cout << "*a, *b, same" << endl;
    else
        cout << "*a, *b, diff" << endl;

    if (c == d)
        cout << "c, d, same" << endl;
    else
        cout << "c, d, diff";
}

class Time {
    int hour;
    int minute;

   public:
    Time(int hour = 0, int minute = 0) : hour{hour}, minute{minute} {}

    Time operator+(int m) {
        // tmp.hour = this->hour + ((this->minute + m) / 60);
        // tmp.minute = this->minute + m;
        // tmp.minute = this->minute % 60;
        int totalMin = this->minute + m + this->hour * 60;
        Time tmp(totalMin / 60, totalMin % 60);
        return tmp;
    }

    void print() {
        cout << hour << ":" << minute << endl;
    }
};

void quiz_33() {
    Time t(10, 45);
    Time result = t + 80;
    t.print();
    result.print();
}

int main() {
    quiz_33();
}