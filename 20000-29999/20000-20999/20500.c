// 20500 Ezreal 여눈부터 가네 ㅈㅈ
// https://www.acmicpc.net/problem/20500
// https://kangwlgns.tistory.com/17(KangJihoon)에서 배웠습니다.
#include <stdio.h>
#define REMAINDER 1000000007

long long dp[1516][3] = {0, }; // dp[x][y] = 1,5로만 구성된 x자리 숫자(5로 끝남)에서 모든 자릿수의 수를 더한 후 3으로 나눌 때 나머지가 y인 숫자들

int main(){
	int N;
	scanf("%d", &N);
	dp[2][0] = 1; // 15
	dp[2][1] = 1; // 55
	dp[2][2] = 0;
	for (int i = 3; i <= N; i++){
		// 한 자리 큰 숫자의 개수 => (숫자 맨 앞에 1 붙이기) + (숫자 맨 뒤에 5 붙이기)
		// 어차피 지금 세는 모든 숫자는 5로 끝나야 하며, 1과 5로만 구성되어있다.
		dp[i][0] = (dp[i - 1][2] + dp[i - 1][1]) % REMAINDER;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % REMAINDER;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][0]) % REMAINDER;
	}
	printf("%lld", dp[N][0]);
}