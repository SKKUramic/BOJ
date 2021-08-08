// 15995 잉여역수 구하기
// https://www.acmicpc.net/problem/15995
#include <stdio.h>

int main(){
	int a, m, x = 1;
	scanf("%d %d", &a, &m);
	while (a * x % m != 1){x++;}
	printf("%d", x);
}