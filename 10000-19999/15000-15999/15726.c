// 15726 이칙 연산
// https://www.acmicpc.net/problem/15726
#include <stdio.h>

int main(){
	long long int a, b, c, max = -99999999;
	scanf("%lld %lld %lld", &a, &b, &c);
	if (b > c){max = (a * b) / c;}
	else {max = (a * c) / b;}
	printf("%lld", max);
}