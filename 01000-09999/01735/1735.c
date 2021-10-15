// 1735 분수 합
// https://www.acmicpc.net/problem/1735
#include <stdio.h>

long long Euclidean(long long a, long long b){
	return a % b ? Euclidean(b, a % b) : b;
}

int main(){
	long long A1, B1, A2, B2, A, B, tmp;
	scanf("%lld %lld", &A1, &B1);
	scanf("%lld %lld", &A2, &B2);
	tmp = Euclidean(B1, B2);
	B = (B1 * B2) / tmp;
	A1 *= (B2 / tmp); A2 *= (B1 / tmp);
	A = A1 + A2;
	tmp = Euclidean(A, B);
	printf("%lld %lld", A / tmp, B / tmp);
}