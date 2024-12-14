#include<iostream>
#include<stack>
using namespace std;

typedef long long ll;
typedef struct _Info {
    ll tall, cnt;
}Info; stack<Info> s;

int n, person;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    cin >> n;

    cin >> person;
    s.push({ person, 1 });

    for (int i = 0; i < n - 1; i++)
    {
        cin >> person;
        int nx_cnt = 1;

        while (!s.empty() && person >= s.top().tall)
        {
            ll tall = s.top().tall, cnt = s.top().cnt;
            s.pop();
            ans += cnt;

            if (person == tall) {
                nx_cnt = cnt + 1;
            }
        }
        if (!s.empty()) ans++;
        s.push({ person, nx_cnt });
    }
    cout << ans << "\n";
}