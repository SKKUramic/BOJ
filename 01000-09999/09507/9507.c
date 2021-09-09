// 9507 Generations of Tribbles
// https://www.acmicpc.net/problem/9507
#include <stdio.h>

long long dp[70] = {1, 1, 2, 4, };

int main(){
	int TC, N;
	for (int i = 4; i <= 67; i++){
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d", &N);
		printf("%lld\n", dp[N]);
	}
}