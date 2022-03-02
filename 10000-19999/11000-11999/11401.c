// 11401 이항 계수 3
// https://www.acmicpc.net/problem/11401
#include <stdio.h>
#define MODULO_NUMBER 1000000007

long long n, r;

long long modulo(long long x){
	long long ret = 1;
	while (x * ret % MODULO_NUMBER != 1){ret++;}
	return ret;
}

long long factorial(long long x){
	long long ret = 1;
	while (x > 1){
		ret = (ret * x) % MODULO_NUMBER;
		x--;
	}
	return ret;
}

int main(){
	long long N, N_R_and_R, K, p, temp;
	p = MODULO_NUMBER - 2;
	scanf("%lld %lld", &n, &r);
	N = factorial(n);
	N_R_and_R = (factorial(n - r) * factorial(r)) % MODULO_NUMBER;
	temp = 1; // a^(p - 1) ≡ 1 (mod p)이면 a^(p - 2) ≡ a^(-1) (mod p)
	while(p > 0){
		if (p % 2 == 1){
			temp = (temp * N_R_and_R) % MODULO_NUMBER;
		}
		N_R_and_R = N_R_and_R * N_R_and_R % MODULO_NUMBER;
		p /= 2;
	}
	N_R_and_R = temp % MODULO_NUMBER;
	printf("%lld", (N * N_R_and_R) % MODULO_NUMBER);
}