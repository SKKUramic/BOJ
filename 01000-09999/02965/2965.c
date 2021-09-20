// 2965 캥거루 세마리
// https://www.acmicpc.net/problem/2965
#include <stdio.h>

int max_num(int a, int b){
	return a > b ? a : b;
}

int main(){
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d", max_num(B - A, C - B) - 1);
}