#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int n, h;
    cin >> n;
    stack<pair<int, int>> tower;
    // 인덱스 0에 최대 높이인 100000001로 푸시함
    // -> 수신하는 탑이 없으면 0번째 탑(더미 데이터)을 가리키도록 함
    tower.push({ 100000001, 0 });
    for (int i = 1; i <= n; i++) {
        cin >> h;
        while (tower.top().first < h)   // h보다 탑에 있는 top의 높이가 클 때까지 pop
            tower.pop();
        cout << tower.top().second << " ";  // top의 인덱스 번호 출력
        tower.push({ h, i }); // 인덱스 번호와 함께 tower에 저장
    }
}