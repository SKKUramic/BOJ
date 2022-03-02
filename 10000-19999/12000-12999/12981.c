// 12981 공 포장하기
// https://www.acmicpc.net/problem/12981
#include <stdio.h>

int main(){
	int R, G, B, box = 0;
	scanf("%d %d %d", &R, &G, &B);
	box += R / 3;
	box += G / 3;
	box += B / 3;
	R %= 3; G %= 3; B %= 3;
	while (R > 0 && G > 0 && B > 0){
		box++;
		R--; G--; B--;
	}
	box += R / 2;
	box += G / 2;
	box += B / 2;
	R %= 2; G %= 2; B %= 2;
	while (R > 0 && G > 0){
		box++;
		R--; G--;
	}
	while (R > 0 && B > 0){
		box++;
		R--; B--;
	}
	while (B > 0 && G > 0){
		box++;
		B--; G--;
	}
	box += (R + B + G);
	printf("%d", box);
}