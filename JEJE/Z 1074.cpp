#include <iostream>
using namespace std;

int n, r, c, answer = 0;

bool yee(int x, int y, int size)
{
    if (size == 1 && x == r && y == c) return true;
    if (size != 1 && (x <= r && r <= x + size - 1 && y <= c && c <= y + size - 1))
    {
        for (int i = 0; i < 2; i++) {
            if (
                yee(x , y, size / 2)||
                yee(x +size/2, y, size / 2)||
                yee(x, y + size / 2, size / 2)||
                yee(x + size / 2, y + size / 2, size / 2)
                )return true;
        }
    }
    else answer += size * size;
    return false;
}

int main()
{
    cin >> n >> c >> r;
    yee(0, 0, (1 << n));
    cout << answer << '\n';
}