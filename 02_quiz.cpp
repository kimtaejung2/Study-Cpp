#include <array>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void quiz_46();

namespace A {
int value = 10;
}
namespace B {
int value = 20;
}

void quiz_47() {
    cout << "A::value: " << A::value << endl;
    cout << "B::value: " << B::value << endl;
}

void quiz_48();

void quiz_49() {
    enum class Menu {
        Insert = 1,
        Delete,
        Update
    };

    int num;

    cout << "<<Insert: 1, Delete: 2, Update: 3>>" << endl;
    cout << "Input number: ";
    cin >> num;

    Menu menu = Menu(num);
    if (menu == static_cast<Menu>(1))
        cout << "Insert";
    else if (menu == static_cast<Menu>(2))
        cout << "Delete";
    else if (menu == static_cast<Menu>(3))
        cout << "Update";
    else
        cout << "Wrong input";
}

void quiz_50() {
    double price{3500.75};
    int count{static_cast<int>(3.5)};
    int total{static_cast<int>(price) * count};
    cout << "count = " << count << '\n';
    cout << "total = " << total << '\n';
}

void quiz_51() {
    array<int, 5> arr{3, 8, 2, 10, 5};
    int sum = 0;
    int max = arr.front();
    for (int n : arr) {
        sum += n;
        if (max < n)
            max = n;
    }
    cout << "sum = " << sum << endl;
    cout << "max = " << max << endl;
}

void quiz_52() {
    vector<int> v;
    cout << "정수 5개 입력 > ";  // 1 2 3 4 5

    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        if (n % 2 == 0) v.emplace_back(n);  // v.push_back(n)
    }

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\ncount = " << v.size() << endl;
}

void printResult(initializer_list<int> values) {
    int sum;
    int count = 0;
    for (int v : values) {
        if (v >= 5) {
            sum += v;
            count++;
        }
    }
    cout << "count = " << count << endl;
    cout << "sum = " << sum << endl;
}

void quiz_53() {
    printResult({3, 8, 2, 10, 5});
}

void quiz_54();

void quiz_55();

void quiz_56();

void quiz_57();

void quiz_58();

int main() {
}