// 3004 체스판 조각
// https://www.acmicpc.net/problem/3004
#include <stdio.h>

int main(){
	int N, a, b;
	a = 1; b = 1;
	scanf("%d", &N);
	while (N > 0){
		if (N % 2 == 1){a++;}
		else {b++;}
		N--;
	}
	printf("%d", a * b);
}