// 2293 동전 1
// https://www.acmicpc.net/problem/2293
#include <stdio.h>

int coin[101] = {0, };
int dp[10001] = {0, };

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++){
		scanf("%d", &coin[n]);
	}
	dp[0] = 1; // 0원을 만드는 방법은 한 가지, 동전을 안 쓰는 것
	// n + 1개의 동전으로 만들 수 있는 경우들을 구한다. (첫번째 동전부터 사용)
	// 놀랍게도 동전의 순서에 관계없이 제대로 구할 수 있다.
	// dp(k원, n개의 동전 사용) = dp(k - (동전가격)원, n개의 동전 사용) + dp(k원, n - 1개의 동전 사용)
	for (int n = 0; n < N; n++){
		for (int k = 1; k <= K; k++){
			if (k >= coin[n]){
				dp[k] += dp[k - coin[n]]; //dp(k, n - 1)은 이미 이전 시도에서 구했으며, 그 값은 dp[k]에 담겨 있다. 따라서 dp(k - coin[n], n)을 더해주면 된다.
			}
		}
	}
	printf("%d", dp[K]);
}