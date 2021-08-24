// 16395 파스칼의 삼각형
// https://www.acmicpc.net/problem/16395
#include <stdio.h>

long long triangle[31][31] = {0, };

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	for (int n = 1; n <= 30; n++){
		for (int k = 1; k <= n; k++){
			if (n == 1 || n == k){triangle[n][k] = 1;}
			else {triangle[n][k] = triangle[n - 1][k - 1] + triangle[n - 1][k];}
		}
	}
	printf("%lld", triangle[N][K]);
}