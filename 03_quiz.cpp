#include <iostream>
#include <string>
using namespace std;

void quiz_42();

void quiz_43();

void quiz_44() {
    string str;
    cout << "문자열 입력 > ";
    getline(cin, str);

    cout << "length = " << str.length() << endl;
    cout << "first = " << str.front() << endl;
    cout << "last = " << str.back() << endl;
}

void quiz_45() {
    string str;
    cout << "문자열 입력 > ";
    getline(cin, str);

    int indexOfC = str.find("C++");

    if (indexOfC != -1) {
        cout << str.substr(indexOfC) << endl;
    } else {
        cout << "not found" << endl;
    }
}

void quiz_46();

void quiz_47() {
    const int num = 50;
    const int& refn = num;
    cout << "ref num: " << refn << endl;
}

int number = 40;
int& getnumber() {
    int& refn = number;
    return refn;
}

void quiz_48() {
    int& num2 = getnumber();
    num2 += 40;
    cout << number << ", " << num2 << endl;
}

void quiz_49();

void quiz_50();

void quiz_51();

bool average(int arr[], int size, int& avg) {
    if (size == 0) return false;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    avg = sum / size;
    return true;
}

void quiz_52() {
    int numbers[] = {10, 20, 30, 40};
    int avg;
    if (average(numbers, sizeof(numbers) / sizeof(int), avg))
        cout << "average = " << avg;
    else
        cout << "error";
}

void quiz_53();

int& findMax(int arr[], int size) {
    int mIndex = 0;

    for (int i = 0; i < size; i++) {
        if (arr[mIndex] < arr[i]) mIndex = i;
    }
    return arr[mIndex];
}

void quiz_54() {
    int numbers[] = {10, 40, 20, 30};
    findMax(numbers, 4) = 100;
    for (int value : numbers)
        cout << value << " ";
}

int main() {
    quiz_54();
    return 0;
}