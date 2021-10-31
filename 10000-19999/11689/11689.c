// 11689 GCD(n, k) = 1
// https://www.acmicpc.net/problem/11689
#include <stdio.h>

long long prime_number[100];
int prime_cnt = 0;

int main(){
	long long N, temp;
	scanf("%lld", &N);
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
	printf("%lld", N);
}