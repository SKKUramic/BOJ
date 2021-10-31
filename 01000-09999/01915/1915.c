// 1915 가장 큰 정사각형
// https://www.acmicpc.net/problem/1915
#include <stdio.h>

int DP[1001][1001] = {0, };
char square[1001][1001];

int min_square(int a, int b, int c){
	if (a < b){
		if (a < c){return a;}
		else {return c;}
	}
	else {
		if (b < c){return b;}
		else {return c;}
	}
}

int main(){
	int N, M, MAX_SIZE = 0;
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++){
		scanf("%s", square[n]);
	}
	for (int n = 1; n <= N; n++){
		for (int m = 1; m <= M; m++){
			if (square[n - 1][m - 1] == '1'){
				DP[n][m] = min_square(DP[n - 1][m - 1], DP[n - 1][m], DP[n][m - 1]) + 1;
			}
			if (DP[n][m] > MAX_SIZE){MAX_SIZE = DP[n][m];}
		}
	}
	printf("%d", MAX_SIZE * MAX_SIZE);
}