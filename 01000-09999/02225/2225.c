// 2225 합분해
// https://www.acmicpc.net/problem/2225
#include <stdio.h>

long long decompose[201][201] = {0, };
long long answer = 0;

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	for (int x = 0; x <= N; x++){
		decompose[1][x] = 1;
	}
	for (int k = 2; k <= K; k++){
		for (int cost = 0; cost <= N; cost++){
			for (int n = 0; n <= N - cost; n++){
				decompose[k][n + cost] += decompose[k - 1][n];
				decompose[k][n + cost] %= 1000000000;
			}
		}
	}
	printf("%lld", decompose[K][N] % 1000000000);
}