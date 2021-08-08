// 2630 색종이 만들기
#include <bits/stdc++.h>
using namespace std;

const int INVALID = -1;
const int WHITE = 0;
const int BLUE = 1;

int n;
int ans[2];
int paper[130][130];
int dy[] = {0, 0, 1, 1};
int dx[] = {0, 1, 0, 1};

int f(int y, int x, int len) {
    if (len == 1) return paper[y][x];
    int ret = paper[y][x];
    int cnt[2] = {0, 0};
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * len / 2;
        int nx = x + dx[i] * len / 2;
        int color = f(ny, nx, len / 2);
        if (color != INVALID) {
            cnt[color]++;
        }
        if (ret != color) {
            ret = INVALID;
        }
    }
    if (ret == INVALID) {
        ans[0] += cnt[0];
        ans[1] += cnt[1];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    int color = f(0, 0, n);
    if (color != INVALID) {
        ans[color]++;
    }
    cout << ans[0] << '\n' << ans[1] << endl;
}
