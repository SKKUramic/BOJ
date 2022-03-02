// 10599 페르시아의 왕들
// https://www.acmicpc.net/problem/10599
#include <stdio.h>

int main(){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	while (a != 0 || b != 0 || c != 0 || d != 0){
		printf("%d %d\n", c - b, d - a);
		scanf("%d %d %d %d", &a, &b, &c, &d);
	}
}