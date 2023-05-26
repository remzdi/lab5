#include "functions.h"

TTriad::TTriad(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

void TTriad::Increase(int n, int m, int p) {
    a += n;
    b += m;
    c += p;
}

void TTriad::Decrease(int n, int m, int p) {
    a -= n;
    b -= m;
    c -= p;
}

void TTriad::Print() const {
    cout << a << ":" << b << ":" << c << endl;
}

TTime::TTime(int a, int b, int c) : TTriad(a, b, c) {}

void TTime::Print() const {
    cout << a << ":" << b << ":" << c << " (Time)" << endl;
}

TDate::TDate(int a, int b, int c) : TTriad(a, b, c) {}

void TDate::Print() const {
    cout << a << ":" << b << ":" << c << " (Date)" << endl;
}

void GenerateDates(TTriad** triads, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int day = std::rand() % 26 + 6; // random day between 6 and 31
        int month = std::rand() % 12 + 1; // random month between 1 and 12
        int year = std::rand() % 100 + 1; // random year between 1 and 100

        TDate* date = new TDate(day, month, year);
        triads[i] = date;
    }
}

void GenerateTimes(TTriad** triads, int m) {
    srand(time(0));
    for (int i = 0; i < m; i++) {
        int hour = rand() % 24; // random hour between 0 and 23
        int minute = rand() % 45; // random minute between 0 and 44
        int second = rand() % 60; // random second between 0 and 59

        TTime* time = new TTime(hour, minute, second);
        triads[i] = time;
    }
}

void getInput(int& n, int& m) {
    cout << " Enter the number of dates to generate: ";
    cin >> n;

    cout << "Enter the number of times to generate: ";
    cin >> m;
}

void printDates(TTriad** triads, int n) {
    cout << "Our dates: " << endl;
    for (int i = 0; i < n; i++) {
        triads[i]->Print();
    }
}

void printTimes(TTriad** triads, int m) {
    cout << "Our times: " << endl;
    for (int i = 0; i < m; i++) {
        triads[i]->Print();
    }
}

void printGoodDates(TTriad** triads, int n) {
    cout << "Dates that are available as time:" << endl;
    for (int i = 0; i < n; i++) {
        if (triads[i]->a >= 0 && triads[i]->a < 24 && triads[i]->b >= 0 && triads[i]->b < 60 && triads[i]->c >= 0 && triads[i]->c < 60) {
            triads[i]->Print();
        }
    }
}

void printDecreasedDates(TTriad** triads, int n) {
    cout << "Dates decreased by 5 days:" << endl;
    for (int i = 0; i < n; i++) {
        triads[i]->Decrease(5, 0, 0);
        triads[i]->Print();
    }
}

void increaseTimes(TTriad** triads, int m) {
    cout << "Times increased by 15 minutes:" << endl;
    for (int i = 0; i < m; i++) {
        triads[i]->Increase(0, 15, 0);
        triads[i]->Print();
    }
}

void deleteTriads(TTriad** triads, int n) {
    for (int i = 0; i < n; i++) {
        delete triads[i];
    }
    delete[] triads;
}
