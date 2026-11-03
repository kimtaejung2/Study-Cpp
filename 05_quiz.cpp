#include <iostream>
#include <string>
using namespace std;

class Circle {
   private:
    int radius;

   public:
    Circle() : radius(1) {}
    Circle(int radius) : radius(radius) {}
    void setRadius(int radius) {
        this->radius = radius;
    }
    double getArea() const {
        return 3.14 * radius * radius;
    }
};

void quiz_42() {
    Circle cArr[3];
    int size = sizeof(cArr) / sizeof(Circle);

    Circle* p = cArr;

    for (int i = 0; i < size; i++) {
        (p + i)->setRadius(i + 1);
        cout << (p + i)->getArea() << endl;
    }
}

class StudentA {
   private:
    int score;

   public:
    StudentA() : score(0) {}
    void setScore(int score) {
        this->score = score;
    }
    int getScore() const {
        return score;
    }
};

void quiz_43() {
    int student;
    cout << "?¬Ý? ???? ??????? > ";
    cin >> student;

    int score = 0;
    int sum = 0;
    double avg;
    cout << "?? ?¬Ý??? ?????? ??????? >";
    StudentA* stArr = new StudentA[student];
    for (int i = 0; i < student; i++) {
        cin >> score;
        (stArr + i)->setScore(score);
    }
    for (int i = 0; i < student; i++) {
        sum += (stArr + i)->getScore();
    }
    avg = sum / student;
    cout << "?¬Ý????? ??? ???? :" << avg;

    delete[] stArr;
    stArr = nullptr;
}

class ScoreList {
   private:
    int* scores;
    int size;

   public:
    ScoreList() = default;
    ScoreList(int s);
    ~ScoreList();
    void setScore(int index, int score);
    int getAverage();
};

ScoreList::ScoreList(int s) {
    size = s;
    scores = new int[size];
}

ScoreList::~ScoreList() {
    delete[] scores;
}

void ScoreList::setScore(int index, int score) {
    scores[index] = score;
}

int ScoreList::getAverage() {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }

    return (static_cast<double>(sum) / size);
}

void quiz_44() {
    ScoreList scores(3);

    scores.setScore(0, 80);
    scores.setScore(1, 90);
    scores.setScore(2, 100);

    cout << scores.getAverage();
}

// ??? ??? delete nullptr?? ???? ???? ?????? ?????? ???.
void quiz_45() {
    int* p = nullptr;
    for (int i = 1; i <= 3; i++) {
        p = new int[3];
        p[0] = i;
        p[1] = i * 10;
        p[2] = i * 100;
        cout << p[2] << '\n';
        delete[] p;
        p = nullptr;
    }
}

void quiz_46() {
    int* arr = nullptr;
    arr = new int[3];
    delete[] arr;
    arr = nullptr;
}

class StudentB {
    string* name;
    int* id;

   public:
    StudentB(string n, int i);
    ~StudentB();
};

StudentB::StudentB(string n, int i) {
    string* name = new string(n);
    int* id = new int(i);
}

StudentB::~StudentB() {
    delete name;
    delete id;
}

void quiz_47();  // Student class

void quiz_48() {
    int* p = new int{20};
    delete p;
    p = nullptr;
}

int main() {
    quiz_45();
    return 0;
}