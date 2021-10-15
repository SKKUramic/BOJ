// 10707 수도요금
// https://www.acmicpc.net/problem/10707
#include <stdio.h>

int main(){
	int A, B, C, D, P, X, Y;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &P);
	X = P * A;
	if (P <= C){
		Y = B;
	}
	else {
		Y = B + (P - C) * D;
	}
	if (X < Y){
		printf("%d", X);
	}
	else {
		printf("%d", Y);
	}
}