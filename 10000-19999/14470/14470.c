// 14470 전자레인지
// https://www.acmicpc.net/problem/14470
#include <stdio.h>

int main(){
	int A, B, C, D, E;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
	if (A < 0){
		printf("%d", (-A) * C + D + B * E);
	}
	else {
		printf("%d", (B - A) * E);
	}
}