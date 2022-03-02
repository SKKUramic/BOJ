// 2355 시그마
// https://www.acmicpc.net/problem/2355
#include <stdio.h>

long long sum(long long n){
	return n * (n + 1) / 2;
}

int main(){
	long long A, B, temp;
	scanf("%lld %lld", &A, &B);
	if (A > B){
		temp = A;
		A = B;
		B = temp;
	}
	if (A < 0){ // A가 음수일 때
		if (B < 0){ // B도 음수일 때
			printf("%lld", -(sum(-A) - sum(-B) - B));
		}
		else {
			printf("%lld", sum(B) - sum(-A));
		}
	}
	else if (A == B){ // 둘 다 0 이상의 정수일 때, 둘이 같다면
		printf("%lld", A);
	}
	else if (A < B){
		printf("%lld", sum(B) - sum(A) + A);
	}
	else {
		printf("%lld", sum(A) - sum(B));
	}
}