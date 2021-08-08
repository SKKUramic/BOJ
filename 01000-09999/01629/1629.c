// 1629 곱셈
#include <stdio.h>

unsigned long long int A, B, C, answer = 1;

int main(){
	scanf("%lld %lld %lld", &A, &B, &C);
	while (B > 0){
		if (B % 2 == 1){
			answer = (answer * A) % C;
		}
		A = (A * A) % C;
		B /= 2;
	}
	printf("%lld", answer);
}