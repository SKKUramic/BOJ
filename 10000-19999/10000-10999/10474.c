// 10474 분수좋아해?
// https://www.acmicpc.net/problem/10474
#include <stdio.h>

int main(){
	long long A = -1, B = -1;
	scanf("%lld %lld", &A, &B);
	while (A != 0 || B != 0){
		printf("%lld %lld / %lld\n", A / B, A % B, B);
		scanf("%lld %lld", &A, &B);
	}
}