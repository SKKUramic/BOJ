// 16431 베시와 데이지
// https://www.acmicpc.net/problem/16431
#include <stdio.h>
#include <stdlib.h>

int MAX(int x, int y){return x > y ? x : y;}

int main(){
	int BX, BY, DX, DY, JX, JY;
	scanf("%d %d", &BX, &BY);
	scanf("%d %d", &DX, &DY);
	scanf("%d %d", &JX, &JY);
	if (abs(JX - DX) + abs(JY - DY) < MAX(abs(JX - BX), abs(JY - BY))){
		printf("daisy");
	}
	else if (abs(JX - DX) + abs(JY - DY) > MAX(abs(JX - BX), abs(JY - BY))){
		printf("bessie");
	}
	else {
		printf("tie");
	}
}