// 15818 오버플로우와 모듈러
// https://www.acmicpc.net/problem/15818
#include <stdio.h>

long long int number[101];

int main(){
	long long int N, M;
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++){
		scanf("%lld", &number[i]);
	}
	long long int answer = number[0] % M;
	for (int i = 1; i < N; i++){
		answer = ((answer % M) * (number[i] % M)) % M;
	}
	printf("%lld", answer);
}