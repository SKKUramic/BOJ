// 13707 합분해 2
// https://www.acmicpc.net/problem/2225
#include <stdio.h>
#define REMAIN 1000000000

long long decompose[5001][5001] = {0, };

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	for (int n = 1; n <= 5000; n++){
		for (int k = 1; k <= 5000; k++){ // 그냥 다 계산해~~~~~
			if (n == 1){decompose[n][k] = k;} // 0 k-1개와 1 1개로 조합가능한 방법은 k가지
			else {
				decompose[n][k] = (decompose[n - 1][k] + decompose[n][k - 1]) % REMAIN;
				// decompose[n - 1][k]에서는 아무 곳에나 1을 더하고, decompose[n][k - 1]에서는 0을 추가하면 된다. (물론 중복 경우는 제거)
			}
		}
	}
	printf("%lld", decompose[N][K] % REMAIN);
}