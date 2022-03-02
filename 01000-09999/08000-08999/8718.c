// 8718 Bałwanek
// https://www.acmicpc.net/problem/8718
#include <stdio.h>

int main(){
	long long x, k;
	scanf("%lld %lld", &x, &k);
	if (k * 7000 <= x * 1000){ // 지금 만든 눈덩이가 머리
		printf("%lld", k * 7000);
	}
	else if (k * 3500 <= x * 1000){ // 지금 만든 눈덩이가 몸통
		printf("%lld", k * 3500);
	}
	else if (k * 1750 <= x * 1000){ // 지금 만든 눈덩이가 맨 아래
		printf("%lld", k * 1750);
	}
	else { // 못 만든다
		printf("0");
	}
}