// 10164 격자상의 경로
// https://www.acmicpc.net/problem/10164
#include <stdio.h>

int DP[16][16] = {0, };

int main(){
	int N, M, K, X = 1, Y = 1;
	scanf("%d %d %d", &N, &M, &K);
	for (int y = 1; y <= N; y++){
		for (int x = 1; x <= M; x++){
			if ((y - 1) * M + x == K){
				Y = y; X = x;
			}
		}
	}
	DP[1][1] = 1;
	//printf("%d %d\n", Y, X);
	for (int y = 1; y <= Y; y++){
		for (int x = 1; x <= X; x++){
			if (y != 1 || x != 1){DP[y][x] = DP[y - 1][x] + DP[y][x - 1];}
		}
	}
	for (int y = Y; y <= N; y++){
		for (int x = X; x <= M; x++){
			if (y != Y || x != X){DP[y][x] = DP[y - 1][x] + DP[y][x - 1];}
		}
	}
	//printf("%d\n", DP[Y][X]);
	printf("%d", DP[N][M]);
}