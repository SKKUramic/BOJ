// 2294 동전 2
// https://www.acmicpc.net/problem/2294
// 2293 동전 1 문제 코드를 개량하여 만들었습니다.
#include <stdio.h>

int coin[101] = {0, };
int dp[10001] = {0, };

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++){
		scanf("%d", &coin[n]);
	}
	for (int x = 1; x <= 10000; x++){dp[x] = 10001;}
	for (int n = 0; n < N; n++){
		for (int k = 1; k <= K; k++){
			if (k >= coin[n] && dp[k - coin[n]] + 1 < dp[k]){ // 지금 'dp[k원까지 드는 코인 개수]'보다 'dp[k = coin[n]원까지 드는 개수] + n번째 코인 하나'가 더 작을 경우 갱신함
				dp[k] = dp[k - coin[n]] + 1;
			}
		}
	}
	if (dp[K] == 10001){printf("-1");}
	else {printf("%d", dp[K]);}
}