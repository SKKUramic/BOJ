// 1520 내리막 길
// https://www.acmicpc.net/problem/1520
#include <stdio.h>

long long map[501][501] = {0, };
long long dp[501][501] = {0, }; // map[y][x]에서 map[N - 1][M - 1]까지 가는 경로의 수
int N, M;
long long answer = 0;

long long DFS(int y, int x){
	if (dp[y][x] != -1) {return dp[y][x];}
	if (y == N - 1 && x == M - 1){return 1;}
	long long count = 0;
	if (y > 0 && map[y][x] > map[y - 1][x]) {count += DFS(y - 1, x);}
	if (y < N - 1 && map[y][x] > map[y + 1][x]) {count += DFS(y + 1, x);}
	if (x > 0 && map[y][x] > map[y][x - 1]) {count += DFS(y, x - 1);}
	if (x < M - 1 && map[y][x] > map[y][x + 1]) {count += DFS(y, x + 1);}
	return dp[y][x] = count;
}

int main(){
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			scanf("%lld", &map[n][m]);
			dp[n][m] = -1; // 초기화, 길이 없는 경우도 있을 수 있으므로 0으로 하지 않음
		}
	}
	answer = DFS(0, 0);
	printf("%lld", answer);
}