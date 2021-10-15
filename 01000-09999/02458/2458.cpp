// 2458 키 순서
// https://www.acmicpc.net/problem/2458
#include <iostream>
using namespace std;

int N, M;
bool Taller[501][501];

void Floyd_Warshall(int n){
	for (int k = 1; k <= n; k++){
		for (int start = 1; start <= n; start++){
			for (int end = 1; end <= n; end++){
				if (Taller[start][k] == true && Taller[k][end] == true){
					Taller[start][end] = true;
				}
			}
		}
	}
	return;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int start, end, count, answer = 0;
	cin >> N >> M;
	for (int m = 0; m < M; m++){
		cin >> start >> end;
		Taller[start][end] = true;
	}
	Floyd_Warshall(N);
	for (int n = 1; n <= N; n++){
		count = 0;
		for (int k = 1; k <= N; k++){
			if (k != n && (Taller[n][k] == true || Taller[k][n] == true)){count++;}
		}
		if (count == N - 1){answer++;}
	}
	cout << answer;
}