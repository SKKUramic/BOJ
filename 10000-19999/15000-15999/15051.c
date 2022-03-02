// 15051 Máquina de café
// https://www.acmicpc.net/problem/15051
#include <stdio.h>

int three_min(int a, int b, int c){
	if (a < b){
		if (a < c){return a;}
		else {return c;}
	}
	else {
		if (b < c){return b;}
		else {return c;}
	}
}

int main(){
	int a1, a2, a3;
	int t1, t2, t3;
	scanf("%d %d %d", &a1, &a2, &a3);
	t1 = 2 * a2 + 4 * a3;
	t2 = 2 * (a1 + a3);
	t3 = 2 * a2 + 4 * a1;
	printf("%d", three_min(t1, t2, t3));
}