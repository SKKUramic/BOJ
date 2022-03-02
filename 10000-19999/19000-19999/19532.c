// 19532 수학은 비대면강의입니다
// https://www.acmicpc.net/problem/19532
#include <stdio.h>

int main(){
	int a, b, c, d, e, f;
	int x, y;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	x = ((c * e) - (f * b)) / ((a * e) - (d * b));
	y = ((c * d) - (f * a)) / ((b * d) - (e * a));
	printf("%d %d", x, y);
}