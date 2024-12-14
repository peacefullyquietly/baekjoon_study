#include<iostream>
using namespace std;
typedef __uint128_t l;

string stoI(l result)
{
    string r = ""; 
    string f = to_string((long long) (result /  (__uint128_t) pow(10, 15))); 
    string s = to_string((long long) (result % (__uint128_t) pow(10, 15))); 
    if ( f == "0") return s;
    else return f + s; 
}

l reverse(string s) {
    l result = 0;
    l power = 1;
    for (int i = 0; i < s.length(); i++) {
        result += (s[i] - '0') * power;
        power *= 10;
    }
    return result;
}

int main()
{
    l a, b;
    cin >> a >> b;
}