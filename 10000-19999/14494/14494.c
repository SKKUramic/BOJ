// 14494 다이나믹이 뭐예요?
// https://www.acmicpc.net/problem/14494
#include <stdio.h>
#define MODULO 1000000007

long long dp[1001][1001] = {0, };

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for (int y = 1; y <= N; y++){
		for (int x = 1; x <= M; x++){
			if (y == 1 || x == 1){dp[y][x] = 1;}
			else {dp[y][x] = (dp[y - 1][x - 1] + dp[y - 1][x] + dp[y][x - 1]) % MODULO;}
		}
	}
	printf("%lld", dp[N][M]);
}