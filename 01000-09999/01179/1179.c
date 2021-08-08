// 1179 마지막 요세푸스 문제
// https://www.acmicpc.net/problem/1179
// https://en.wikipedia.org/wiki/Josephus_problem 위키워요 고마피디아!
#include <stdio.h>

long long Josephus(long long n, long long k){
	if (k == 1){return n - 1;}
	if (n == 1){return 0;}
	if (n < k){
		return (Josephus(n - 1, k) + k) % n;
	}
	else {
		long long n_prime = n - n / k;
		long long JOSEPHUS = Josephus(n_prime, k) - n % k;
		if (JOSEPHUS < 0) {JOSEPHUS += n_prime;}
		return (k * (JOSEPHUS % n_prime)) / (k - 1);
	}
}

int main(){
	long long N, K;
	scanf("%lld %lld", &N, &K);
	printf("%lld", 1 + Josephus(N, K));
}