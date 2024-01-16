#include <iostream>
#include <list>
using namespace std;

int main(void) {
    string str;
    cin >> str;
    list<char> L;
    for (auto c : str)
        L.push_back(c);
    list<char>::iterator cursor = L.end();
    // auto cursor = L.end(); ¿Í °°À½
    
    int m;
    string command;
    string character;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> command;
        if (command == "L") {
            if (cursor != L.begin())
                cursor--;
        } else if (command == "D") {
            if (cursor != L.end())
                cursor++;
        } else if (command == "B") {
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        } else if (command == "P") {
            char add;
            cin >> add;
            L.insert(cursor, add);
        }
    }
    for (auto c : L)
        cout << c;
}