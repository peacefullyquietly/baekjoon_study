// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include <math.h>
using namespace std;

int zx1, zy1, zr1, zx2, zy2, zr2;

int dot2dot()
{
    return pow(zx2 - zx1, 2)+pow(zy2 - zy1,2);
}

int turet()
{
    int d;
    d = dot2dot();
    //zr1 = min(zr1, zr2); zr2 = max(zr1, zr2);
    if(d == 0 && zr1 == zr2){
        if(zr1 != 0)return -1;
        else return 1;
    }
    if(pow(zr1 + zr2, 2) > d && pow(zr2 - zr1, 2) < d) return 2;
    if(pow(zr1 + zr2, 2) == d || pow(zr2 - zr1, 2) == d) return 1;
    return 0;
} 

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> zx1 >> zy1 >> zr1 >> zx2 >> zy2 >> zr2;
        cout << turet() << '\n';
    }
}