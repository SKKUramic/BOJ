// 2738 행렬 덧셈
// https://www.acmicpc.net/problem/2738
#include <stdio.h>

int A[101][101];

int main(){
	int N, M, num;
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			scanf("%d", &A[n][m]);
		}
	}
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			scanf("%d", &num);
			A[n][m] += num;
		}
	}
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			printf("%d ", A[n][m]);
		}
		printf("\n");
	}
}