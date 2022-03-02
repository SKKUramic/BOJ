// 2903 중앙 이동 알고리즘
// https://www.acmicpc.net/problem/2903
#include <stdio.h>

int main(){
	int N;
	unsigned long long point = 3; // N이 1일 때의 답은 4
	scanf("%d", &N);
	for (int i = 1; i < N; i++){
		point = 2 * point - 1;
	}
	printf("%lld", point * point);
}