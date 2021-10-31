// 9625 BABBA
// https://www.acmicpc.net/problem/9625
#include <stdio.h>

int main(){
	long long DP[50] = {0, };
	DP[0] = 0; DP[1] = 1; DP[2] = 1;
	for (int i = 3; i <= 46; i++){
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	int X;
	scanf("%d", &X);
	printf("%lld %lld", DP[X - 1], DP[X]);
}