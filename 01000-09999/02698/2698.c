// 2698 인접한 비트의 개수
// https://www.acmicpc.net/problem/2698
#include <stdio.h>

long long adjacency_bit[101][101][2] = {0, }; // adjacency_bit[자리수][비트 인접 수][0으로 끝남, 1로 끝남] -> 조건을 만족하는 숫자의 개수

int main(){
	int T, N, K;
	scanf("%d", &T);
	adjacency_bit[1][0][0] = 1; // 0 1개
	adjacency_bit[1][0][1] = 1; // 1 1개
	for (int len = 2; len <= 100; len++){
		adjacency_bit[len][0][0] = adjacency_bit[len - 1][0][0] + adjacency_bit[len - 1][0][1];
		adjacency_bit[len][0][1] = adjacency_bit[len - 1][0][0];
		for (int adj = 1; adj < len; adj++){
			adjacency_bit[len][adj][0] = adjacency_bit[len - 1][adj][0] + adjacency_bit[len - 1][adj][1]; // 비트 인접 수가 같은 숫자들에 0이 붙은 숫자들을 더함
			adjacency_bit[len][adj][1] = adjacency_bit[len - 1][adj][0] + adjacency_bit[len - 1][adj - 1][1]; // 비트 인접 수가 같은 0으로 끝나는 숫자 + 비트 인접 수가 1 작은 1로 끝나는 숫자
		}
	}
	while (T-- > 0){
		scanf("%d %d", &N, &K);
		if (N <= K || K <= 1){printf("0\n"); continue;}
		else {
			printf("%lld\n", adjacency_bit[N][K][0] + adjacency_bit[N][K][1]);
		}
	}
}