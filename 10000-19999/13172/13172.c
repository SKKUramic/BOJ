// 13172 Σ
// https://www.acmicpc.net/problem/13172
#include <stdio.h>
#define MODULO 1000000007

long long answer = 0;

long long calculate(long long a, long long b){
	long long m = MODULO - 2;
	long long ret = 1;
	while (m > 0){
		if (m % 2 == 1){
			ret = (ret * b) % MODULO;
		}
		b = (b * b) % MODULO;
		m /= 2;
	}
	ret = (ret * a) % MODULO;
	return ret;
}

int main(){
	long long N, S;
	int M;
	scanf("%d", &M);
	while (M-- > 0){
		scanf("%lld %lld", &N, &S);
		answer = (answer + calculate(S, N)) % MODULO;
	}
	printf("%lld", answer);
}