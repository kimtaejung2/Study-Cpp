#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void ex_01() {
    double quiz, mterm, fterm;
    cout << "퀴즈, 중간고사, 기말고사 성적을 입력하세요 : ";
    cin >> quiz >> mterm >> fterm;
    cout << "total : " << fixed << setprecision(1) << quiz + mterm + fterm << endl;
    cout << "average : " << fixed << setprecision(2) << (quiz + mterm + fterm) / 3.0 << endl;
}

void ex_02() {
    int num;
    string ns;
    cout << "10진수 입력 : ";
    cin >> num;
    cout << endl
         << "여러 진법으로 출력하기 oct(8), hex(16), digit(10)" << endl;
    while (1) {
        cout << "해당 진법 입력 : ";
        cin >> ns;
        if (ns != "oct" && ns != "8" && ns != "hex" && ns != "16" && ns != "digit" && ns != "10") {
            cout << "해당 진법이 없습니다.";
            break;
        }
        if (ns == "oct" || ns == "8") cout << " => 8진법 : " << oct << "0o" << num << endl;
        if (ns == "hex" || ns == "16") cout << " => 16진법 : " << hex << "0x" << num << endl;
        if (ns == "digit" || ns == "10") cout << " => 10진법 : " << dec << num << endl;
    }
}

void ex_03() {
}

void ex_04() {
}

void ex_05() {
}

void ex_06() {
}

int main(void) {
    ex_01();
    return 0;
}