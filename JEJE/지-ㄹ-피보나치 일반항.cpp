// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    std::cout << std::setprecision(1000000);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long double n, a, b, answer; 
    cin >> n;
    a = pow(((1+sqrt(5))/2),n);
    b = pow(((1-sqrt(5))/2),n);
    answer = 1/sqrt(5)*(a-b);
    cout << answer << "\n";
    answer = fmod(answer, 1000000);
    cout << answer << "\n";
}
//부동