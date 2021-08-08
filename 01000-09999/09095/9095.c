// 9095 1, 2, 3 더하기
// https://www.acmicpc.net/problem/9095
// dp를 사용하면 매우 빠르게 풀립니다.
#include <stdio.h>

int dp[100] = {0, };

int one_two_three(int end){
	if (end == 0){return 1;}
	if (dp[end] != 0){return dp[end];}
	int count = 0;
	if (end > 0){
		count += one_two_three(end - 1);
	}
	if (end > 1){
		count += one_two_three(end - 2);
	}
	if (end > 2){
		count += one_two_three(end - 3);
	}
	dp[end] = count;
	return dp[end];
}

int main(){
	int T, dest, answer;
	scanf("%d", &T);
	dp[1] = 1;
	for (int i = 0; i < T; i++){
		scanf("%d", &dest);
		answer = one_two_three(dest);
		printf("%d\n", answer);
	}
}