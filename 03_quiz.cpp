#include <iostream>
#include <string>
using namespace std;

void quiz_42() {
    string s;
    cout << "문자열 입력: ";
    getline(cin, s);
    cout << "입력한 문자열: " << s;
}

void quiz_43() {
    string str1("grape");
    string str2("grapefruit");
    (str1.compare(str2)) ? cout << "X" : cout << "O";
}

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

void quiz_46() {
    string name;
    string sscore;
    int score;
    cout << "이름:점수 입력 > ";
    getline(cin, name, ':');
    cin >> sscore;
    cout << "name = " << name << endl;
    score = stoi(sscore);
    cout << "score = " << score << endl;
    (score >= 60) ? cout << "PASS" : cout << "FAIL";
}

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

void change(int& a, int& b) {
    a += 10;
    b -= 10;
}

void quiz_49() {
    int a = 20;
    int b = 30;

    change(a, b);

    cout << a << " " << b;
}

void divide(int a, int b, int& q, int& r) {
    q = a / b;
    r = a % b;
}

void quiz_50() {
    int quotient;
    int remainder;

    divide(17, 5, quotient, remainder);

    cout << "quotient = " << quotient << endl;
    cout << "remainder = " << remainder;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void quiz_51() {
    int n1, n2;
    cout << "정수 2개 입력: ";
    cin >> n1 >> n2;

    cout << "n1 = " << n1 << endl
         << "n2 = " << n2 << endl;

    swap(n1, n2);
    cout << "swap" << endl;

    cout << "n1 = " << n1 << endl
         << "n2 = " << n2;
}

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

void sortThree(int& a, int& b, int& c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}

void quiz_53() {
    int a = 6;
    int b = 3;
    int c = 1;

    sortThree(a, b, c);
    cout << a << " " << b << " " << c;
}

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
    quiz_53();
    return 0;
}