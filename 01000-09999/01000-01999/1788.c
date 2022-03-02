// 1788 피보나치 수의 확장
// https://www.acmicpc.net/problem/1788
#include <stdio.h>
#include <stdlib.h>
#define ZERO 1000000
#define MODULO 1000000000

long long dp[2000001] = {0, };

int main(){
	int n;
	long long flag;
	dp[ZERO] = 0; dp[ZERO + 1] = 1;
	for (int i = 2; i <= 1000000; i++){
		dp[ZERO + i] = (dp[ZERO + i - 1] + dp[ZERO + i - 2]) % MODULO;
	}
	for (int i = 1; i <= 1000000; i++){
		dp[ZERO - i] = dp[ZERO - i + 2] - dp[ZERO - i + 1];
		if (dp[ZERO - i] < 0){flag = -1;}
		else {flag = 1;}
		dp[ZERO - i] = ((flag * dp[ZERO - i]) % MODULO) * flag;
	}
	flag = -1;
	scanf("%d", &n);
	if (dp[ZERO + n] == 0){
		printf("0\n");
		printf("%lld", dp[ZERO + n]);
	}
	else if (dp[ZERO + n] > 0){
		printf("1\n");
		printf("%lld", dp[ZERO + n]);
	}
	else {
		printf("-1\n");
		printf("%lld", flag * dp[ZERO + n]);
	}
}