// 9465 스티커
// https://www.acmicpc.net/problem/9465
#include <stdio.h>

int sticker[100001][2] = {0, };
int dp[100001][2] = {0, };
int size;

int max_in_three(int a, int b, int c){
	if (a > b){
		if (a > c){
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b > c){
			return b;
		}
		else {
			return c;
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d", &size);
		for (int x = 0; x < 2; x++){
			for (int i = 0; i < size; i++){
				scanf("%d", &sticker[i][x]);
			}
		}
		dp[0][0] = sticker[0][0];	dp[0][1] = sticker[0][1];
		dp[1][0] = sticker[0][1] + sticker[1][0];
		dp[1][1] = sticker[0][0] + sticker[1][1];
		for (int i = 2; i < size; i++){
			dp[i][0] = max_in_three(dp[i - 2][0], dp[i - 2][1], dp[i - 1][1]) + sticker[i][0];
			dp[i][1] = max_in_three(dp[i - 2][0], dp[i - 2][1], dp[i - 1][0]) + sticker[i][1];
		}
		printf("%d\n", dp[size - 1][0] > dp[size - 1][1] ? dp[size - 1][0] : dp[size - 1][1]);
	}
}