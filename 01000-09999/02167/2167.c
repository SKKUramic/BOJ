// 2167 2차원 배열의 합
// https://www.acmicpc.net/problem/2167
#include <stdio.h>

long long arr[301][301] = {0, };

int main(){
	long long sum;
	int N, M, K, i, j, x, y;
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++){
		for (int m = 1; m <= M; m++){
			scanf("%lld", &arr[n][m]);
		}
	}
	scanf("%d", &K);
	for (int k = 0; k < K; k++){
		scanf("%d %d %d %d", &i, &j, &x, &y);
		sum = 0;
		for (int a = i; a <= x; a++){
			for (int b = j; b <= y; b++){
				sum += arr[a][b];
			}
		}
		printf("%lld\n", sum);
	}
}