// 1598 꼬리를 무는 숫자 나열
// https://www.acmicpc.net/problem/1598
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b;
	int ax, bx, ay, by;
	scanf("%d %d", &a, &b);
	ax = (a - 1) % 4;	bx = (b - 1) % 4;
	ay = (a - 1) / 4;	by = (b - 1) / 4;
	printf("%d", abs(ay - by) + abs(ax - bx));
}