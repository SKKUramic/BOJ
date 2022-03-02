// 5618 공약수
// https://www.acmicpc.net/problem/5618
#include <stdio.h>

int three_min(int a, int b, int c){
	if (a < b){
		if (a < c){return a;}
		else {return c;}
	}
	else {
		if (b < c) {return b;}
		else {return c;}
	}
}

int main(){
	int n, limit, a, b, c = 1111111111;
	scanf("%d", &n);
	if (n == 2){scanf("%d %d", &a, &b);}
	else {scanf("%d %d %d", &a, &b, &c);}
	limit = three_min(a, b, c);
	if (n == 2){c = 0;}
	for (int i = 1; i <= limit; i++){
		if (a % i == 0 && b % i == 0 & c % i == 0){
			printf("%d\n", i);
		}
	}
}