#include <iostream>
#include <list>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    list<int> L;
    for (int i = 1; i < a + 1; i++) {
        L.push_back(i);
    }
    cout << '<';
    for (int j = 0; j < a-1; j++) {
        for (int k = 0; k < b-1; k++) {
            L.push_back(L.front());
            L.pop_front();
        }
        cout << L.front() << ", ";
        L.pop_front();
    }
    cout << L.back() << '>';
}