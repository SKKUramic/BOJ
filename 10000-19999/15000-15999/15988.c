// 15988 1, 2, 3 더하기 3
// https://www.acmicpc.net/problem/15988
#include <stdio.h>

long long dp[1000001] = {0, };

int main(){
	int T, N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++){
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	}
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d", &N);
		printf("%lld\n", dp[N]);
	}
}