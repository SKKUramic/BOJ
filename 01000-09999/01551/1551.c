// 1551 수열의 변화
// https://www.acmicpc.net/problem/1551
#include <stdio.h>

int arr[20][20];

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++){
		if (n == N - 1){
			scanf("%d", &arr[0][n]);
		}
		else {
			scanf("%d,", &arr[0][n]);
		}
	}
	for (int k = 1; k <= K; k++){
		for (int i = 0; i < N - k; i++){
			arr[k][i] = arr[k - 1][i + 1] - arr[k - 1][i];
		}
	}
	for (int i = 0; i < N - K; i++){
		if (i == N - K - 1){
			printf("%d", arr[K][i]);
		}
		else {
			printf("%d,", arr[K][i]);
		}
	}
}