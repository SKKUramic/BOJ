// 17874 Piece of Cake!
// https://www.acmicpc.net/problem/17874
#include <stdio.h>

int main(){
	int n, h, v, A, B;
	scanf("%d %d %d", &n, &h, &v);
	A = h > n - h ? h : n - h;
	B = v > n - v ? v : n - v;
	printf("%d", A * B * 4);
}