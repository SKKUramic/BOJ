// 11051 이항 계수 2
#include <stdio.h>

int dp[1001][1001];

int main(){
	int N_index = 0, N, K;
	scanf("%d %d", &N, &K);
	dp[0][0] = 1;
	while (N_index < N){
		N_index++;
		for (int i = 0; i <= N_index; i++){
			if (i == 0 || i == N){
				dp[N_index][i] = 1;
			}
			else {
				dp[N_index][i] = (dp[N_index - 1][i - 1] + dp[N_index - 1][i]) % 10007;
			}
			if (N_index == N && i == K){
				break;
			}
		}
	}
	printf("%d", dp[N][K]);
}