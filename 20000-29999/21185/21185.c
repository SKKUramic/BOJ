// 21185 Some Sum
// https://www.acmicpc.net/problem/21185
#include <stdio.h>

int main(){
	int sum, n;
	scanf("%d", &n);
	if (n % 2 == 1){ // 홀수 개의 숫자를 더하면 안 되지ㅋㅋ
		printf("Either");
	}
	else {
		if ((n / 2) % 2 == 1){
			printf("Odd");
		}
		else {
			printf("Even");
		}
	}
}