// 5557 1학년
// https://www.acmicpc.net/problem/5557
#include <stdio.h>

long long arr[101];
long long DP[101][21] = {0, };

int main(){
	long long N, answer;
	scanf("%lld", &N);
	for (long long n = 0; n < N - 1; n++){
		scanf("%lld", &arr[n]);
	}
	scanf("%lld", &answer);
	DP[0][arr[0]] = 1;
	for (long long n = 1; n < N - 1; n++){
		for (long long i = 0; i <= 20; i++){
			if (i + arr[n] <= 20){
				DP[n][i + arr[n]] += DP[n - 1][i];
			}
			if (i - arr[n] >= 0){
				DP[n][i - arr[n]] += DP[n - 1][i];
			}
		}
	}
	printf("%lld", DP[N - 2][answer]);
}