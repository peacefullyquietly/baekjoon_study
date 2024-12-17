// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

struct info {
    int year, month, day;
};

int D1[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }, D2[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    info start, end;
    cin >> start.year >> start.month >> start.day;
    cin >> end.year >> end.month >> end.day;
    while (1) {
        start.day++;
        if ((start.year % 4 == 0 && start.year % 100 != 0) || start.year % 400 == 0) {
            if (start.day == D2[start.month] + 1) {
                start.day = 1;
                start.month++;
                if (start.month == 13) {
                    start.month = 1;
                    start.year++;
                }
            }
        }
        else {
            if (start.day == D1[start.month] + 1) {
                start.day = 1;
                start.month++;
                if (start.month == 13) {
                    start.month = 1;
                    start.year++;
                }
            }
        }
        ans += start.day + start.month;
        if (start.year == end.year && start.month == end.month && start.day == end.day) break;
    }
    cout << ans << ' ' << ans * 2;
}