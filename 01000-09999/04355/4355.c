// 4355 서로소
// https://www.acmicpc.net/problem/4355
#include <stdio.h>

long long prime_number[100];
int prime_cnt = 0;

void Euler_phi_function(long long N){
	long long prime_number[100], temp;
	int prime_cnt = 0;
	temp = N;
	for (long long i = 2; i * i <= N; i++){
		if (temp % i == 0){
			prime_number[prime_cnt++] = i;
			while (temp % i == 0){temp /= i;}
		}
	}
	if (temp != 1){prime_number[prime_cnt++] = temp;}
	for (int i = 0; i < prime_cnt; i++){
		N = (prime_number[i] - 1LL) * (N / prime_number[i]);
	}
	printf("%lld\n", N);
	return;
}

int main(){
	long long N, temp;
	scanf("%lld", &N);
	while (N != 0){
		Euler_phi_function(N);
		scanf("%lld", &N);
	}
}