// 1357 뒤집힌 덧셈
// https://www.acmicpc.net/problem/1357
#include <stdio.h>

int REV(int x){
	int ret = 0;
	while (x > 0){
		ret *= 10;
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", REV(REV(a) + REV(b)));
}