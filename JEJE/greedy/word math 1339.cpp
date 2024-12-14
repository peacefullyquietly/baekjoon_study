#include<bits/stdc++.h>
using namespace std;

vector<string> words;
int word_cnt[27];
int pow_arr[] = {0, 1, (int)1e1, (int)1e2, (int)1e3, (int)1e4, (int)1e5, (int)1e6, (int)1e7, (int)1e8, (int)1e9};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    
    cin >> n;
    words.resize(n);

    for(auto &i : words){
        cin >> i;
    }

    for(auto &word : words){
        int j = word.length();
        for(auto &i : word){
            word_cnt[i-'A'] += pow_arr[j--];
        }
    }

    sort(word_cnt, word_cnt+27, greater<int>());

    int ans = 0, flag = 9;
    for(auto &i : word_cnt){
        if(i == 0) break;
        // cout << flag << " || " << i << "\n";
        ans += (flag--*i);
    }

    cout << ans;
}