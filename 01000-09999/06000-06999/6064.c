// 6064 카잉 달력
// https://www.acmicpc.net/problem/6064
#include <stdio.h>
#include <stdbool.h>

int main(){
	bool flags;
	long long int T, M, N, x, y, answer;
	scanf("%lld", &T);
	for (int i = 0; i < T; i++){
		scanf("%lld %lld %lld %lld", &M, &N, &x, &y);
		flags = false;
		answer = -1;
		for (long long int j = x; j < M * N; j += M){
			if (j % N == y){
				answer = j;
				flags = true;
				break;
			}
		}
		if (flags){
			printf("%lld\n", answer);
			continue;	
		}
		for (long long int j = y; j < M * N; j += N){
			if (j % M == x){
				answer = j;
				break;
			}
		}
		printf("%lld\n", answer);
	}
}