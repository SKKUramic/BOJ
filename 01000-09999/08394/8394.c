// 8394 악수
// https://www.acmicpc.net/problem/8394
#include <stdio.h>

short DP[10000001];

int main(){
	int N;
	scanf("%d", &N);
	DP[0] = 0; DP[1] = 1; DP[2] = 2;
	for (int n = 3; n <= N; n++){
		DP[n] = (DP[n - 2] + DP[n - 1]) % 100;
	}
	printf("%d", DP[N] % 10);
}