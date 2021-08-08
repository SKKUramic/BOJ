// 11025 요세푸스 문제 3
// https://www.acmicpc.net/problem/11025
// https://en.wikipedia.org/wiki/Josephus_problem 위키피디아 고마워요!
#include <stdio.h>

int main(){
	int N, K, last_man;
	scanf("%d %d", &N, &K);
	last_man = 1;
	for (int n = 2; n <= N; n++){
		last_man = 1 + (last_man + K - 1) % n;
	}
	printf("%d", last_man);
}