// 19602 Dog Treats
// https://www.acmicpc.net/problem/19602
#include <stdio.h>

int main(){
	int S, M, L;
	scanf("%d %d %d", &S, &M, &L);
	if (S + 2 * M + 3 * L >= 10){printf("happy");}
	else {printf("sad");}
}