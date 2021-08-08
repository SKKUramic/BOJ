// 6987 월드컵
#include <bits/stdc++.h>
using namespace std;

int arr[6][3];

bool check() { return accumulate(&arr[0][0], &arr[6][3], 0) == 30; }

bool f(int depth, int x, int y) {
    if (depth == 15) {
        return true;
    }

    int new_x, new_y;
    if (y == 5) {
        new_x = x + 1;
        new_y = x + 2;
    } else {
        new_x = x;
        new_y = y + 1;
    }

    bool ret = false;

    for (int i = 0; i < 3; i++) {
        if (arr[x][i] > 0 && arr[y][2 - i] > 0) { // 나와 상대의 횟수가 모두 1 이상일 때(승/패, 무/무, 패/승)
            arr[x][i]--;
            arr[y][2 - i]--;
            ret |= f(depth + 1, new_x, new_y);
            arr[x][i]++;
            arr[y][2 - i]++;
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int tc = 0; tc < 4; tc++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> arr[i][j];
            }
        }
        cout << (check() && f(0, 0, 1)) << ' ';
    }
    cout << endl;
}