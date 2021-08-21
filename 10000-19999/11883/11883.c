// 11883 생일수 I
// https://www.acmicpc.net/problem/11883
#include <stdio.h>
#define INF 99999999

int dp[1000001][3] = {0, };

int main(){
	int N, T;
	int digit3, digit5, digit8, not_exist;
	scanf("%d", &T);
	for (int i = 1; i <= 1000000; i++){
		dp[i][0] = INF; dp[i][1] = INF; dp[i][2] = INF;
	}
	// 기저 사례
	dp[3][0] = 1;	dp[3][1] = 0;	dp[3][2] = 0;
	dp[5][0] = 0;	dp[5][1] = 1;	dp[5][2] = 0;
	dp[6][0] = 2;	dp[6][1] = 0;	dp[6][2] = 0;
	dp[8][0] = 0;	dp[8][1] = 0;	dp[8][2] = 1;
	for (int i = 9; i <= 1000000; i++){
		if ((dp[i - 3][0] + 1) + dp[i - 3][1] + dp[i - 3][2] < dp[i][0] + dp[i][1] + dp[i][2]){
			dp[i][0] = dp[i - 3][0] + 1;
			dp[i][1] = dp[i - 3][1];
			dp[i][2] = dp[i - 3][2];
		}
		if (dp[i - 5][0] + (dp[i - 5][1] + 1) + dp[i - 5][2] < dp[i][0] + dp[i][1] + dp[i][2]){
			dp[i][0] = dp[i - 5][0];
			dp[i][1] = dp[i - 5][1] + 1;
			dp[i][2] = dp[i - 5][2];
		}
		if (dp[i - 8][0] + dp[i - 8][1] + (dp[i - 8][2] + 1) < dp[i][0] + dp[i][1] + dp[i][2]){
			dp[i][0] = dp[i - 8][0];
			dp[i][1] = dp[i - 8][1];
			dp[i][2] = dp[i - 8][2] + 1;
		}
	}
	while (T-- > 0){
		scanf("%d", &N);
		if (dp[N][0] == INF){ // 안 되는 경우일 경우
			printf("-1\n");
			continue;
		}
		for (int i = 0; i < dp[N][0]; i++){
			printf("3");
		}
		for (int i = 0; i < dp[N][1]; i++){
			printf("5");
		}
		for (int i = 0; i < dp[N][2]; i++){
			printf("8");
		}
		printf("\n");
	}
}