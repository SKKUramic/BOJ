// 9659 돌 게임 5
// https://www.acmicpc.net/problem/9659
#include <stdio.h>

int main(){
	long long stone;
	scanf("%lld", &stone);
	if (stone % 2 == 0){printf("CY");}
	else if (stone % 2 == 1) {printf("SK");}
}