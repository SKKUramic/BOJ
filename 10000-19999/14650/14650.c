// 14650 걷다보니 신천역 삼 (Small)
// https://www.acmicpc.net/problem/14650
#include <stdio.h>

long long dp[10][3] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	dp[1][0] = 0; dp[1][1] = 1; dp[1][2] = 1;
	dp[2][0] = 2; dp[2][1] = 1; dp[2][2] = 1;
	for (int i = 2; i <= N; i++){
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
	}
	printf("%lld", dp[N][0]);
}