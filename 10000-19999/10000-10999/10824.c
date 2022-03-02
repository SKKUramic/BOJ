// 10824 네 수
// https://www.acmicpc.net/problem/10824
#include <stdio.h>

int main(){
	long long A, B, C, D, X;
	scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
	X = 1;
	while (B >= X){X *= 10;}
	A = A * X + B;
	X = 1;
	while (D >= X){X *= 10;}
	C = C * X + D;
	printf("%lld", A + C);
}