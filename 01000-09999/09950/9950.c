// 9950 Rectangles
// https://www.acmicpc.net/problem/9950
#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while (a != 0 || b != 0 || c != 0){
		if (a == 0){
			printf("%d %d %d\n", c / b, b, c);
		}
		else if (b == 0){
			printf("%d %d %d\n", a, c / a, c);
		}
		else if (c == 0){
			printf("%d %d %d\n", a, b, a * b);
		}
		scanf("%d %d %d", &a, &b, &c);
	}
}