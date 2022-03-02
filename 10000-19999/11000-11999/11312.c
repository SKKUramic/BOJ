// 11312 삼각 무늬 - 2
// https://www.acmicpc.net/problem/11312
#include <stdio.h>

int main(){
	long long int T, A, B, n;
	scanf("%lld", &T);
	while (T-- > 0){
		scanf("%lld %lld", &A, &B);
		n = A / B;
		printf("%lld\n", n * n);
	}
}