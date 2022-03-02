// 2588 곱셈
#include <stdio.h>

int main(int argc, char* argv[]) {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d\n%d\n%d\n%d", a*(b % 10), a*(((int)(b/10))%10), a*((int)(b / 100)), a*b);
}