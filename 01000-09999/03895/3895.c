// 3895 그리고 하나가 남았다
// https://www.acmicpc.net/problem/3895
// 요세푸스 씨 여기 계셨군요
#include <stdio.h>

int Josephus(int n, int k){
	if (n == 1){return 1;}
	return 1 + (Josephus(n - 1, k) + k - 1) % n;
}

int main(){
	int N, K, M, last_man;
	scanf("%d %d %d", &N, &K, &M);
	while (N != 0 || K != 0 || M != 0){
		last_man = 1 + (Josephus(N - 1, K) + M - 1) % N; // 일단 1명 죽이고 시작하기 때문에 N 대신 N - 1, K - 1 대신 M - 1을 넣는다.
		printf("%d\n", last_man);
		scanf("%d %d %d", &N, &K, &M);
	}
}