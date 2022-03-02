// 1085 직사각형에서 탈출
#include <stdio.h>

int main(){
	int x, y, w, h;
	int min = 9999;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	if (min > w - x){
		min = w - x;
	}
	if (min > x){
		min = x;
	}
	if (min > h - y){
		min = h - y;
	}
	if (min > y){
		min = y;
	}
	printf("%d", min);
}