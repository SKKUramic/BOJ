// 10869 사칙연산
#include <stdio.h>

int main(int argc, char* argv[]) {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n%d\n%d\n%d\n%d", a+b, a-b, a*b, a/b, a%b);
}