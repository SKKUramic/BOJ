// 20363 당근 키우기
// https://www.acmicpc.net/problem/20363
#include <stdio.h>

int main(){
	int X, Y, answer;
	scanf("%d %d", &X, &Y);
	if (X > Y){
		answer = (X + Y) + Y / 10;
	}
	else {
		answer = (X + Y) + X / 10;
	}
	printf("%d", answer);
}