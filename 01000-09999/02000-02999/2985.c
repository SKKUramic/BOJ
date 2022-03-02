// 2985 세 수
// https://www.acmicpc.net/problem/2985
#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a + b == c){printf("%d+%d=%d", a, b, c);}
	else if (a - b == c){printf("%d-%d=%d", a, b, c);}
	else if (a * b == c){printf("%d*%d=%d", a, b, c);}
	else if (a / b == c && a % b == 0){printf("%d/%d=%d", a, b, c);}
	else if (a == b + c){printf("%d=%d+%d", a, b, c);}
	else if (a == b - c){printf("%d=%d-%d", a, b, c);}
	else if (a == b * c){printf("%d=%d*%d", a, b, c);}
	else if (a == b / c && 0 == b % c){printf("%d=%d/%d", a, b, c);}
}