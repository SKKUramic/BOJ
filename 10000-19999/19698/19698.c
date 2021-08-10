// 19698 헛간 청약
// https://www.acmicpc.net/problem/19698
#include <stdio.h>

int main(){
	int cow, W, H, L;
	scanf("%d %d %d %d", &cow, &W, &H, &L);
	if ((W/L) * (H/L) < cow){printf("%d", (W/L) * (H/L));}
	else {printf("%d", cow);}
}