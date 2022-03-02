// 2133 타일 채우기
// https://www.acmicpc.net/problem/2133
#include <stdio.h>

long long DP[31] = {0, };

int main(){
	int N;
	DP[2] = 3;
	scanf("%d", &N);
	for (int i = 4; i <= 30; i += 2){
		DP[i] = 3 * DP[i - 2];
		for (int k = i - 4; k > 0; k -= 2){
			DP[i] += 2 * DP[k]; // 3 * 2 공간보다 더 큰 공간이 요구되는 예외 사항
		}
		DP[i] += 2; // 예외 사항으로 완전히 꽉 찬 것
	}
	printf("%lld", DP[N]);
}