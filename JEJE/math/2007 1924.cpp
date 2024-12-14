// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
using namespace std;

int daysOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string dayOfWeek[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main() {
    int month, day;
    cin >> month >> day;
    for (int i = 1; i < month; ++i) {
        day += daysOfMonth[i];
    }
    cout << dayOfWeek[day % 7] << '\n';
    return 0;
}