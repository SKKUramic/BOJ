// 13171 A
// https://www.acmicpc.net/problem/13171
#include <stdio.h>

int main(){
	long long A, X, answer = 1, REMAINDER = 1000000007;
	scanf("%lld %lld", &A, &X);
	A %= REMAINDER;
	while (X > 0){
		if (X % 2 == 1){
			answer = (answer * A) % REMAINDER;
		}
		A = (A * A) % REMAINDER;
		X /= 2;
	}
	printf("%lld", answer);
}