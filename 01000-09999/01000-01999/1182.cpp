// 1182 부분수열의 합
#include <bits/stdc++.h>
using namespace std;

int n, s;
int ans;
int arr[25];

void f(int idx, int sum) {
    if (idx == n) {
        if (sum == s) ans++;
    } else {
        f(idx + 1, sum);
        f(idx + 1, sum + arr[idx]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    f(0, 0);
    if (s == 0) ans--;
    cout << ans << endl;
}