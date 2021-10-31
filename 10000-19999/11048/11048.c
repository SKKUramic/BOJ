// 11048 이동하기
// https://www.acmicpc.net/problem/11048
#include <stdio.h>

int candy[1001][1001], DP[1001][1001] = {0, };

int max_candy(int a, int b, int c){
	if (a > b){
		if (a > c){return a;}
		else {return c;}
	}
	else {
		if (b > c){return b;}
		else {return c;}
	}
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++){
		for (int m = 1; m <= M; m++){
			scanf("%d", &candy[n][m]);
		}
	}
	for (int n = 1; n <= N; n++){
		for (int m = 1; m <= M; m++){
			DP[n][m] = max_candy(DP[n - 1][m - 1], DP[n - 1][m], DP[n][m - 1]) + candy[n][m];
		}
	}
	printf("%d", DP[N][M]);
}