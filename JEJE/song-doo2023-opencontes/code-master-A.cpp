// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    string a;

    unordered_map<string, string> b = {
        {"SONGDO" , "HIGHSCHOOL"},
        {"CODE" , "MASTER"},
        {"2023" , "0611"},
        {"ALGORITHM" , "CONTEST"}
    };
    cin >> a;
    cout << b[a] << '\n';

}