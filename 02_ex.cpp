#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void ex_01() {
    double quiz, mterm, fterm;
    cout << "퀴즈, 중간고사, 기말고사 점수를 입력하세요 : ";
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
        cout << "해당 진법 입ㄹ력 : ";
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
    enum class RPC { Rack = 1,
                     Paper,
                     Scissors };
    int num;
    while (1) {
        cout << "정수 입력(1, 2, 3이 나닌 수는 프로그램 종료) : ";
        cin >> num;
        if (num != 1 && num != 2 && num != 3) break;

        RPC rpc = static_cast<RPC>(num);
        cout << "\t";
        switch (rpc) {
            case RPC::Rack:
                cout << "Rack" << endl;
                break;
            case RPC::Paper:
                cout << "Paper" << endl;
                break;
            case RPC::Scissors:
                cout << "Scissors" << endl;
                break;
        }
    }
}

void ex_04() {
    double dou;
    cout << "실수를 입력하세요 : ";
    cin >> dou;
    cout << endl
         << "정수 part : " << static_cast<int>(dou) << endl
         << "소수 part : " << dou - static_cast<int>(dou);
}

char list_exam(initializer_list<char> li, char ch) {
    int diff = 1000;
    char min;
    for (auto v : li) {
        if (diff > abs(ch - v)) {
            diff = abs(ch - v);
            min = v;
        }
    }
    return min;
}

void ex_05() {
    cout << "{ 'd', 'p', 'r', 'w', 'g', 'f' }문자 중 h와 가까운 문자는 : ";
    cout << list_exam({'d', 'p', 'r', 'w', 'g', 'f'}, 'h') << endl;
    cout << "{ 'k', 'q', 'b', 'r', 'a', 'e', 'v', 'z'}문자 중 w와 가까운 문자는 : ";
    cout << list_exam({'k', 'q', 'b', 'r', 'a', 'e', 'v', 'z'}, 'w') << endl;
}

void ex_06() {
    array<int, 5> arr;
    cout << "정수 입력 : " << endl;
    for (int i = 0; i < arr.size(); i++) cin >> arr[i];
    cout << "배열에 저장된 내용 : ";
    for (auto v : arr) cout << v << " ";
    cout << endl
         << "배열 오름차순 정렬 : ";
    sort(arr.begin(), arr.end());
    for (auto v : arr) cout << v << " ";
}

int main(void) {
    ex_06();
    return 0;
}