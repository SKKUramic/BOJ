// 5073 삼각형과 세 변
// https://www.acmicpc.net/problem/5073
#include <stdio.h>

int three_max(int a, int b, int c){
	if (a > b){
		if (a > c) {return a;}
		else {return c;}
	}
	else {
		if (b > c) {return b;}
		else {return c;}
	}
}

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while (a != 0 || b != 0 || c != 0){
		if (three_max(a, b, c) >= a + b + c - three_max(a, b, c)){
			printf("Invalid\n");
		}
		else if (a == b && b == c && c == a){
			printf("Equilateral\n");
		}
		else if (a == b || b == c || c == a){
			printf("Isosceles\n");
		}
		else {
			printf("Scalene\n");
		}
		scanf("%d %d %d", &a, &b, &c);
	}
}