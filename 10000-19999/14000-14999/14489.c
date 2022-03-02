// 14489 치킨 두 마리 (...)
// https://www.acmicpc.net/problem/14489
#include <stdio.h>

int main(){
	long long A, B, C;
	scanf("%lld %lld", &A, &B);
	scanf("%lld", &C);
	if (A + B >= 2 * C){
		printf("%lld", A + B - 2 * C);
	}
	else {
		printf("%lld", A + B);
	}
}