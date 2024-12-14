// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
    #include<iostream>
    using namespace std;

    int main()
    {
        ios_base::sync_with_stdio(0);cin.tie(0);
        
        int a, b;

        while(1)
        {
            cin >> a >> b;
            if(a == 0 && b == 0) break;
            if(a>b) cout << "Yes";
            else cout << "No";
            cout << '\n';
        }
    }