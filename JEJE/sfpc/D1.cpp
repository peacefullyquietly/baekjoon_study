#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c; cin >> a >>b >> c;
    cout << min(min(a / 40, b / 50), c / 30);
}