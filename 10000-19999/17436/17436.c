// 17436 소수의 배수
// https://www.acmicpc.net/problem/17436
#include <stdio.h>

long long answer = 0, M;
long long arr[10];
int N;

void prime(int idx, long long num, int count){
	if (num > M){return;} // 너무 큰데요
	if (idx == N - 1 && num != 1LL){
		if (count % 2 == 1){answer += M / num;}
		else {answer -= M / num;}
		return;
	}
	prime(idx + 1, num * arr[idx + 1], count + 1);
	prime(idx + 1, num, count);
	return;
}

int main(){
	scanf("%d %lld", &N, &M);
	for (int i = 0; i < N; i++){
		scanf("%lld", &arr[i]);
	}
	for (int i = 0; i < N; i++){
		prime(i, arr[i], 1);
	}
	printf("%lld", answer);
}