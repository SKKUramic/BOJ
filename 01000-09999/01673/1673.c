// 1673 치킨 쿠폰
// https://www.acmicpc.net/problem/1673
#include <stdio.h>

int main(){
	long long N, K, chicken = 0, coupon = 0;
	while (scanf("%lld %lld", &N, &K) != EOF){
		while (N > 0){
			chicken += N;
			coupon += N % K;
			N = (N / K);
			if (coupon >= K){
				N += coupon / K;
				coupon %= K;
			}
		}
		printf("%lld\n", chicken);
		chicken = 0; coupon = 0;
	}
}