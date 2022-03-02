// 1720 타일 코드
// https://www.acmicpc.net/problem/1720
#include <stdio.h>

long long DP[31] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	DP[0] = 1; DP[1] = 1;
	for (int i = 2; i <= 30; i++){
		DP[i] += DP[i - 1] + 2 * DP[i - 2];
		// 1x2 블록 추가 혹은 2x2, 2x1 2개 추가
	}
	// DP[N] = 대칭임 + 대칭 아님
	// 답: 대칭임 + 대칭 아님 = (DP[N] + 대칭임) / 2
	// 홀수일 때: 중앙에 1x2 블록을 두고 대칭임
	// 짝수일 때: 중앙 기준 대칭 + 2x2 블록을 두고 대칭 + 2x1 블록 2개를 두고 대칭
	if (N % 2 == 1){
		printf("%lld", (DP[N] + DP[(N - 1)/ 2]) / 2);
	}
	else {
		printf("%lld", (DP[N] + DP[N / 2] + 2 * DP[N / 2 - 1]) / 2);
	}
}