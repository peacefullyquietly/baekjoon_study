#include <iostream>
#include <queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n, num, answer = 0, x=0, y=0;;
  priority_queue<int, vector<int>, greater<int>> pq;
  cin >> n;
  while(cin >> num) pq.push(num);
  while(!pq.empty() && n>1)
  {  
      x = pq.top(); pq.pop();
      y = pq.top(); pq.pop();
      answer += x+y;;
      if(!pq.empty())pq.push(x+y);   
  }
  cout << answer << '\n';
  return 0;
}