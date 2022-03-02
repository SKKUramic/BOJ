// 1080 행렬
#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<string> A, B;

void flip(int x, int y){
	for (int a = x; a < x + 3; a++){
		for (int b = y; b < y + 3; b++){
			A[a][b] = (A[a][b] == '0' ? '1' : '0');
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	A.resize(N);
	B.resize(N);
	for (auto &i : A) cin >> i;
	for (auto &i : B) cin >> i;
	
	for (int x = 0; x < N; x++){
		for (int y = 0; y < M; y++){
			if (A[x][y] != B[x][y]){
				if (x < N - 2 && y < M - 2){
					flip(x, y);
					ans++;
				}
				else {
					cout << "-1" << endl;
					return 0;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}