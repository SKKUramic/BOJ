// 13699 점화식
// https://www.acmicpc.net/problem/13699
#include <stdio.h>

long long dp[40] = {1, };

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < 35; i++){
		for (int j = 0; j <= i; j++){
			dp[i + 1] += dp[j] * dp[i - j];
		}
	}
	printf("%lld", dp[N]);
}