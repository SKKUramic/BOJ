// 2740 행렬 곱셈
#include <stdio.h>

int arr1[100][100];
int arr2[100][100];
int pos[100][100] = {0, };

int main(){
	int N, M, K;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%d", &arr1[i][j]);
		}
	}
	scanf("%d %d", &M, &K);
	for (int i = 0; i < M; i++){
		for (int j = 0; j < K; j++){
			scanf("%d", &arr2[i][j]);
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < K; j++){
			for (int k = 0; k < M; k++){
				pos[i][j] += arr1[i][k] * arr2[k][j];
			}
			printf("%d ", pos[i][j]);
		}
		printf("\n");
	}
}