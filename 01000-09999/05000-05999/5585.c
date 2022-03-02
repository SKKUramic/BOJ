// 5585 거스름돈
// https://www.acmicpc.net/problem/5585
#include <stdio.h>

int coin[6] = {500, 100, 50, 10, 5, 1};

int main(){
	int change, money, count = 0, idx = 0;
	scanf("%d", &money);
	change = 1000 - money;
	while (change != 0){
		while (change >= coin[idx]){
			change -= coin[idx];
			count++;
		}
		idx++;
	}
	printf("%d", count);
}