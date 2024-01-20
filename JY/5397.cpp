#include <iostream>
#include <list>
using namespace std;

int main(void) {
    int a;
    cin >> a;
    string input;

    for (int i = 0; i < a; i++) {
        list<char> L;
        cin >> input;
        auto cursor = L.begin();
        for (char c : input) {
            if (c == '<') {
                if (cursor != L.begin())
                    cursor--;
            } else if(c == '>') {
                if (cursor != L.end())
                    cursor++;
            }
            else if (c == '-') {
                if (cursor != L.begin()) {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else {
                L.insert(cursor, c);
            }
        }
        for (auto c : L)
            cout << c;
        cout << '\n';
    }
}