// 1890 점프
// https://www.acmicpc.net/problem/1890
#include <stdio.h>

int board[101][101] = {0, };
long long dp[101][101] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d", &board[i][j]);
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			int move = board[i][j];
			if (i == N && j == N){continue;}
			if (i + move <= N){
				dp[i + move][j] += dp[i][j];
			}
			if (j + move <= N){
				dp[i][j + move] += dp[i][j];
			}
		}
	}
	printf("%lld", dp[N][N]);
}