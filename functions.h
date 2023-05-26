#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class TTriad {
public:
    int a, b, c;
public:
    TTriad(int a = 0, int b = 0, int c = 0);
    virtual void Increase(int n, int m, int p);
    virtual void Decrease(int n, int m, int p);
    virtual void Print() const;
};

class TTime : public TTriad {
public:
    TTime(int a = 0, int b = 0, int c = 0);
    void Print() const override;
};

class TDate : public TTriad {
public:
    TDate(int a = 0, int b = 0, int c = 0);
    void Print() const override;
};

void GenerateDates(TTriad** triads, int n);
void GenerateTimes(TTriad** triads, int m);
void getInput(int& n, int& m);
void printDates(TTriad** triads, int n);
void printTimes(TTriad** triads, int m);
void printGoodDates(TTriad** triads, int n);
void printDecreasedDates(TTriad** triads, int n);
void increaseTimes(TTriad** triads, int m);
void deleteTriads(TTriad** triads, int n);

#endif  // FUNCTIONS_H
