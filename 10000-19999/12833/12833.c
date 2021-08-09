// 12833 XORXORXOR
// https://www.acmicpc.net/problem/12833
#include <stdio.h>

int main(){
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (C % 2 == 0){
		printf("%d", A);
	}
	else {
		printf("%d", A^B);
	}
}