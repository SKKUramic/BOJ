// 1562 계단 수
// https://www.acmicpc.net/problem/1562
#include <stdio.h>

long long dp[101][10][1024] = {0, }; // [자리수][끝자리][어떤 숫자를 채웠는가]
long long REMAINDER = 1000000000, answer = 0;

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 1; i < 10; i++){
		dp[1][i][(1 << i)] = 1;
	}
	for (int n = 2; n <= N; n++){
		for (int Lidx = 0; Lidx < 10; Lidx++){
			for (int used = 0; used < 1024; used++){
				if (Lidx != 0){
					dp[n][Lidx][(1 << Lidx) | used] += dp[n - 1][Lidx - 1][used];
				}
				if (Lidx != 9){
					dp[n][Lidx][(1 << Lidx) | used] += dp[n - 1][Lidx + 1][used];
				}
				dp[n][Lidx][(1 << Lidx) | used] %= REMAINDER;
			}
		}
	}
	for (int i = 0; i < 10; i++){answer = (answer + dp[N][i][1023]) % REMAINDER;}
	printf("%lld", answer);
}