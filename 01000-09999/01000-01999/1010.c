// 1010 다리 놓기
// 11051 이항 계수 2의 코드와 매우 동일합니다
#include <stdio.h>

unsigned int Combination(int N, int K){
	unsigned int dp[1001][1001];
	unsigned int N_index = 0;
	dp[0][0] = 1;
	while (N_index < N){
		N_index++;
			for (int i = 0; i <= N_index; i++){
			if (i == 0 || i == N){
				dp[N_index][i] = 1;
			}
			else {
				dp[N_index][i] = (dp[N_index - 1][i - 1] + dp[N_index - 1][i]);
			}
			if (N_index == N && i == K){
				break;
			}
		}
	}
	return dp[N][K];
}

int main(){
	unsigned int N_index = 0, N, K, temp;
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d %d", &N, &K);
		if (N < K){
			temp = K;
			K = N;
			N = temp;
		}
		temp = Combination(N, K);
		printf("%d\n", temp);
	}
}