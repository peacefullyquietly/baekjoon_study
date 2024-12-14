// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <stdio.h>
#include <vector>

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        float sum = 0, avr;
        int n, cnt = 0;
        
        scanf("%d", &n);
        std::vector<int> real(n);
        
        for (int& i : real)
        {
            scanf("%d", &i);
            sum += i;
        }
        
        avr = sum / n;
        
        for (int& i : real)
        {
            if (i > avr) cnt++;
        }
        printf("%d.%d%d%d%%\n",cnt*100/n,cnt*1000/n%10,cnt*10000/n%10,cnt*100000/n%10+((cnt*1000000/n%10>=5)?1:0));
    }
}