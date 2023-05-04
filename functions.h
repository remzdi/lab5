#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class TTriad {
public:
    int a, b, c;
public:
    TTriad(int a = 0, int b = 0, int c = 0);
    void Increase(int n, int m, int p);
    void Decrease(int n, int m, int p);
    void Print() const;
};

class TTime : public TTriad {
public:
    TTime(int a = 0, int b = 0, int c = 0);
};

class TDate : public TTriad {
public:
    TDate(int a = 0, int b = 0, int c = 0);
    TTime ToTime() const;
};

void GenerateDates(TDate* dates, int n);
void GenerateTimes(TTime* times, int m);
void getInput(int& n, int& m);
void generateDates(TDate* dates, int n);
void printDates(TDate* dates, int n);
void generateTimes(TTime* times, int m);
void printTimes(TTime* times, int m);
void printGoodDates(TDate* dates, int n);
void printDecreasedDates(TDate* dates, int n);
void increaseTimes(TTime* times, int m);
