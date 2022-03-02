// 15712 등비수열
// https://www.acmicpc.net/problem/15712
#include <stdio.h>

long long a, r, n, mod;

long long power(long long R, long long N){
	long long ret = 1;
	while (N > 0){
		if (N % 2 == 1){
			ret = (ret * R) % mod;
		}
		R = R * R % mod;
		N /= 2;
	}
	return ret;
}

long long rn_1(long long N){// r^(0부터 N - 1까지)의 합 % mod
	if (N == 0){return 1;} // a
	if (N == 1){return (1 + r) % mod;} //a + ar
	if (N % 2 == 1){
		return (rn_1(N / 2) * (1 + power(r, N / 2 + 1))) % mod;
	}
	else {
		return (rn_1(N / 2 - 1) * (1 + power(r, N / 2)) + power(r, N) % mod) % mod;
	}
}

int main(){
	scanf("%lld %lld %lld %lld", &a, &r, &n, &mod);
	printf("%lld", a * rn_1(n - 1) % mod); 
}