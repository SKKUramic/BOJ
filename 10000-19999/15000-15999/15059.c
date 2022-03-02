// 15059 Hard choice
// https://www.acmicpc.net/problem/15059
#include <stdio.h>

int main(){
	int A, B, C, a, b, c, count = 0;
	scanf("%d %d %d", &A, &B, &C);
	scanf("%d %d %d", &a, &b, &c);
	if (A < a){
		count += a - A;
	}
	if (B < b){
		count += b - B;
	}
	if (C < c){
		count += c - C;
	}
	printf("%d", count);
}