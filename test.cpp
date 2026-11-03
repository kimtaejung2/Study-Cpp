#include <algorithm>
#include <array>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class A {
    int id;

   public:
    A() : A(0) {
        cout << "d ";
    }
    A(int i) {
        id = i;
        cout << "C" << id;
    }
    ~A() {
        cout << "D" << id;
    }
};

A a(9);

int main() {
    A b(1);
    A c;
    cout << ", ";
}