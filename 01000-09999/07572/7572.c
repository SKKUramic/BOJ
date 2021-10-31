// 7572 간지(干支)
// https://www.acmicpc.net/problem/7572
#include <stdio.h>

char GANJI[12] = "ABCDEFGHIJKL";

int main(){
	int num;
	scanf("%d", &num);
	num += 56;
	printf("%c%d", GANJI[num % 12], num % 10);
}