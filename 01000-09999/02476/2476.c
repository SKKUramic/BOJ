// 2476 주사위 게임
// https://www.acmicpc.net/problem/2476
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
	int N, max_price = -1, price;
	int a, b, c;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d %d %d", &a, &b, &c);
		if (a == b && b == c && c == a){
			price = 10000 + a * 1000;
		}
		else if (a == b){
			price = 1000 + a * 100;
		}
		else if (b == c){
			price = 1000 + b * 100;
		}
		else if (c == a){
			price = 1000 + c * 100;
		}
		else {
			price = three_max(a, b, c) * 100;
		}
		if (max_price < price) {max_price = price;}
	}
	printf("%d", max_price);
}