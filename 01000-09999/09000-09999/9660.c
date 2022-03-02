// 9660 돌 게임 6
// https://www.acmicpc.net/problem/9660
#include <stdio.h>

int main(){
	int arr[7] = {0, 1, 0, 1, 1, 1, 1};
	long long stone;
	scanf("%lld", &stone);
	if (arr[stone % 7] == 0){printf("CY");}
	else {printf("SK");}
}