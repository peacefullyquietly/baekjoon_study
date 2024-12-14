#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> st;
string s;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> s;
    for(auto &i : s)
    {
        if(i >= 'A' && i <= 'Z'){
            cout << i;
        }else if(i == '('){
            st.push(i);
        }else if(i == ')'){
            while(!st.empty() && st.top() != '(')
            {
                cout << st.top(); st.pop();
            }
            st.pop();
        }else if(i == '*' || i == '/'){
            while(!st.empty() && (st.top() == '*' || st.top() == '/'))
            {
                cout << st.top(); st.pop();
            }
            st.push(i);
        }else{
            while(!st.empty() && st.top() != '(')
            {
                cout << st.top(); st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty())
    {
        cout << st.top(); st.pop();
    }

    cout << '\n';
    //A*(B*C)*D
}