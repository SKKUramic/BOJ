// 14924 폰 노이만과 파리
// https://www.acmicpc.net/problem/14924
// 이게 되네ㅋㅋ
#include <stdio.h>

int main(){
	int S, T, D;
	scanf("%d %d %d", &S, &T, &D);
	printf("%d", T * ((D / S) / 2));
}