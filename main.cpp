#include "functions.h"

int main() {
    int n, m;
    getInput(n, m);

    TTriad** triads = new TTriad*[n + m];
    TTriad** dates = triads;
    TTriad** times = triads + n;

    GenerateDates(dates, n);
    GenerateTimes(times, m);

    cout << endl;
    cout << "Before processing:" << endl;
    printDates(dates, n);
    printTimes(times, m);
    cout << endl;

    printGoodDates(dates, n);
    cout << endl;

    printDecreasedDates(dates, n);
    cout << endl;

    increaseTimes(times, m);
    cout << endl;

    deleteTriads(triads, n + m);

    return 0;
}
