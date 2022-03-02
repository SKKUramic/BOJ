// 2475 검증수
#include <stdio.h>

int main() {
	int a, b, c, d, e, X;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	X = a * a + b * b + c * c + d * d + e * e;
	printf("%d", X % 10);
}