// 5580 빙고 게임
// https://www.acmicpc.net/problem/5580
#include <stdio.h>

long long DP[50][3001] = {0, }; // [사용한 숫자 수][총합]

int main(){
	int N, NN;
	long long M, S;
	long long MOD = 100000;
	scanf("%d %lld %lld", &N, &M, &S);
	NN = N * N;
	DP[0][0] = 1; // 기저
	for (int m = 1; m <= M; m++){ // 이번에 더할 숫자, 겹치면 안 되므로 작은 숫자부터
		for (int n = NN; n >= 1; n--){ // 지금까지 사용한 숫자의 개수
			for (int s = m; s <= S; s++){ // n개의 숫자를 사용했을 때의 합
				DP[n][s] = (DP[n][s] + DP[n - 1][s - m]) % MOD;
			}
		}
	}
	printf("%lld", DP[NN][S]);
}