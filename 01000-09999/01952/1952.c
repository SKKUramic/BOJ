// 1952 달팽이2
// https://www.acmicpc.net/problem/1952
#include <stdio.h>

int main(){
	int a, b, cnt = 0;
	scanf("%d %d", &a, &b);
	if (a <= b){
		printf("%d", a * 2 - 2);
	}
	else {
		printf("%d", b * 2 - 1);
	}
}