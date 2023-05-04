#include "functions.h"
int main() {
    int n, m;
    getInput(n, m);

    TDate *dates = new TDate[n];
    generateDates(dates, n);
    printDates(dates, n);

    TTime *times = new TTime[m];
    generateTimes(times, m);
    printTimes(times, m);

    printGoodDates(dates, n);
    printDecreasedDates(dates, n);

    increaseTimes(times, m);

    return 0;
}
