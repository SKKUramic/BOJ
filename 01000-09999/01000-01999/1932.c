// 1932 정수 삼각형
#include <stdio.h>

int triangle[500][500];
int dp[500][500];
int max = -1;
// 둘 다 공간 낭비가 큼

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j <= i; j++){
			scanf("%d", &triangle[i][j]);
		}
	}
	dp[0][0] = triangle[0][0];
	for (int i = 0; i < N; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0){
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == i){
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] > dp[i - 1][j] ? dp[i - 1][j - 1] + triangle[i][j] : dp[i - 1][j] + triangle[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++){
		if (max < dp[N - 1][i]){
			max = dp[N - 1][i];
		}
	}
	printf("%d", max);
}