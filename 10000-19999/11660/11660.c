// 11660 구간 합 구하기 5
// https://www.acmicpc.net/problem/11660
#include <stdio.h>

int arr[1025][1025] = {0, };
int dp[1025][1025] = {0, };

int main(){
	int N, M, x1, x2, y1, y2;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d", &arr[i][j]);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j]; // 입력받는 대로 (1, 1) 부터 (i, j)까지의 합을 구하는 공식
		}
	}
	for (int i = 0; i < M; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]); // (x1, y1)부터 (x2, y2)까지의 합을 구하는 공식
	}
}