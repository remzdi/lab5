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

TTime::TTime(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

TDate::TDate(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

TTime TDate::ToTime() const {
    return TTime(a, b, c);
}

void GenerateDates(TDate* dates, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int year = rand() % 100 + 1; // random year between 1 and 100
        int month = rand() % 12 + 1; // random month between 1 and 12
        int day = rand() % 26 + 6; // random day between 6 and 31

        // Adjust day for the length of the month
        switch (month) {
            case 2: // February
                if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                    // Leap year
                    day = (day > 29) ? 29 : day;
                } else {
                    // Not a leap year
                    day = (day > 28) ? 28 : day;
                }
                break;
            case 4: // April
            case 6: // June
            case 9: // September
            case 11: // November
                day = (day > 30) ? 30 : day;
                break;
            default: // All other months
                // Do nothing
                break;
        }

        TDate date(day, month, year);
        dates[i] = date;
    }
}

void GenerateTimes(TTime* times, int m) {
    srand(time(0));
    for (int i = 0; i < m; i++) {
        int hour = rand() % 24; // random hour between 0 and 23
        int minute = rand() % 45; // random minute between 0 and 44
        int second = rand() % 60; // random second between 0 and 59
        TTime time(hour, minute, second);
        times[i] = time;
    }
}

void getInput(int& n, int& m) {
    char er, ch;

    do {
        er = 0;
        cout << "Enter the number of dates to generate: ";
        scanf_s("%d%c", &n, &ch);
        cout << endl;
        if ((ch != '\n') || (n < 2)) {
            er = 1;
            fflush(stdin);
            printf("Incorrect input n \n");
        }
    } while (er);

    do {
        er = 0;
        cout << "Enter the number of times to generate: ";
        scanf_s("%d%c", &m, &ch);
        cout << endl;
        if ((ch != '\n') || (m < 2)) {
            er = 1;
            fflush(stdin);
            printf("Incorrect input m \n");
        }
    } while (er);
}

void generateDates(TDate* dates, int n) {
    GenerateDates(dates, n);
}

void printDates(TDate* dates, int n) {
    cout << "Our dates: " << endl;
    for (int i = 0; i < n; i++) {
        dates[i].Print();
    }
}

void generateTimes(TTime* times, int m) {
    GenerateTimes(times, m);
}

void printTimes(TTime* times, int m) {
    cout << "Our times: " << endl;
    for (int i = 0; i < m; i++) {
        times[i].Print();
    }
}

void printGoodDates(TDate* dates, int n) {
    cout << "Good dates: " << endl;
    for (int i = 0; i < n; i++) {
        bool isValidTime = (dates[i].a >= 6 && dates[i].a <= 23) && (dates[i].c >= 1 && dates[i].c <= 59);
        if (isValidTime) {
            dates[i].ToTime().Print();
        }
    }
}

void printDecreasedDates(TDate* dates, int n) {
    cout << "Decrease dates: " << endl;
    for (int i = 0; i < n; i++) {
        bool isValidTime = (dates[i].a >= 6 && dates[i].a <= 23) && (dates[i].c >= 1 && dates[i].c <= 59);
        if (!isValidTime) {
            dates[i].Decrease(5, 0, 0);
            dates[i].Print();
        }
    }
    delete[] dates;
}

void increaseTimes(TTime* times, int m) {
    cout << "Increase time: " << endl;
    for (int i = 0; i < m; i++) {
        times[i].Increase(0, 15, 0);
        times[i].Print();
    }
    delete[] times;
}
