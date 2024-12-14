#include<iostream>
using namespace std;

int main()
{
    int want, n = 0, moviesuom = 1;
    cin >> want;
    while(want)
    {
        moviesuom += 1;
        n = moviesuom;
        while(n > 0)
        {
            if(n % 1000 == 666)
            {
                want--;
                break;
            }
            else n /= 10;
        }
    }
    cout << moviesuom << '\n';
}