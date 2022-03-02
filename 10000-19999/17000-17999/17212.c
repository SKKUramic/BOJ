// 17212 달나라 토끼를 위한 구매대금 지불 도우미
// https://www.acmicpc.net/problem/17212
#include <stdio.h>

int dp[100001] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	dp[1] = 1; dp[2] = 1; dp[3] = 2; dp[4] = 2; dp[5] = 1; dp[6] = 2; dp[7] = 1;
	for (int n = 8; n <= N; n++){
		dp[n] = 999999;
		if (dp[n] > dp[n - 1] + 1){dp[n] = dp[n - 1] + 1;}
		if (dp[n] > dp[n - 2] + 1){dp[n] = dp[n - 2] + 1;}
		if (dp[n] > dp[n - 5] + 1){dp[n] = dp[n - 5] + 1;}
		if (dp[n] > dp[n - 7] + 1){dp[n] = dp[n - 7] + 1;}
	}
	printf("%d", dp[N]);
}