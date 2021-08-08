// 13985 Equality
// https://www.acmicpc.net/problem/13985
#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d + %d = %d", &a, &b, &c);
	if (a + b == c){
		printf("YES");
	}
	else {
		printf("NO");
	}
}