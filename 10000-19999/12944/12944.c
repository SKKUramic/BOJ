// 17436 소수의 배수
// https://www.acmicpc.net/problem/17436
#include <stdio.h>

long long answer = 0, N;
long long arr[21];
int K;

long long Euclidean(long long a, long long b){ // 아 제발 시간제한만은
	return a % b ? Euclidean(b, a % b) : b;
}

void coprime(int idx, long long num, int count){
	if (num > N){return;} // 너무 큰데요
	if (idx == K - 1 && num != 1LL){
		if (count % 2 == 1){answer += N / num;}
		else {answer -= N / num;}
		return;
	}
	coprime(idx + 1, (num * arr[idx + 1]) / Euclidean(num, arr[idx + 1]), count + 1);
	coprime(idx + 1, num, count);
	return;
}

int main(){
	scanf("%lld %d", &N, &K);
	for (int i = 0; i < K; i++){
		scanf("%lld", &arr[i]);
		if (arr[i] == 1LL){ // 모든 자연수는 1로 나누어 떨어진다
			printf("%lld", N);
			return 0;
		}
	}
	for (int i = 0; i < K; i++){
		coprime(i, arr[i], 1);
	}
	printf("%lld", answer);
}