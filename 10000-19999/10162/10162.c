// 10162 전자레인지
// https://www.acmicpc.net/problem/10162
#include <stdio.h>

int main(){
	int second;
	int count[3] = {0, };
	scanf("%d", &second);
	if (second % 10 != 0){printf("-1");}
	else {
		count[0] = second / 300;
		second %= 300;
		count[1] = second / 60;
		second %= 60;
		count[2] = second / 10;
		printf("%d %d %d", count[0], count[1], count[2]);
	}
}