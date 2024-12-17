// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#define MOD 1000
using namespace std;

vector<vector<long long>> identity_matrix_maker(int size)
{
    vector<vector<long long>> v(size, vector<long long>(size, 0));
        for(int i = 0; i < size; i++){
            v[i][i] = 1;
        }
    return v;
}

vector<vector<long long>> matirix_multiply(vector<vector<long long>>& arr1, vector<vector<long long>>& arr2)
{
    vector<vector<long long>> v(arr1.size(), vector<long long>(arr2[0].size(), 0));
    for(int i = 0; i < arr1.size(); i++){
        for(int j = 0; j < arr2[i].size(); j++){
            for(int k = 0; k < arr1[i].size(); k++){
                v[i][j] += arr1[i][k] * arr2[k][j];
            }
            v[i][j] %= MOD;
        }
    }
    return v;
}

vector<vector<long long>> matrix_power(vector<vector<long long>> arr, long long n)
{

    // if(n==1){
    //     return arr;
    // }

    vector<vector<long long>> v = identity_matrix_maker(arr.size());        
    if(n == 0){
        return v;
    }

    while(n > 0){
        if(n&1){
            v = matirix_multiply(v, arr);
        }
        arr = matirix_multiply(arr, arr);
        n >>= 1;
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<vector<long long>> v;
    
    long long size, n;
    cin >> size;
    cin >> n;
    
    v.resize(size, vector<long long>(size, 0));

    for(auto& i : v){
        for(auto& j : i){
            cin>>j;
            j %= MOD;
        }
    }

    v = matrix_power(v, n);

    for(auto& i : v){
        for(auto& j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
}