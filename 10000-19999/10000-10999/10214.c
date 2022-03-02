// 10214 Baseball
// https://www.acmicpc.net/problem/10214
#include <stdio.h>

int main(){
	int Y, K, TC;
	int a, b;
	scanf("%d", &TC);
	while (TC-- > 0){
		Y = 0; K = 0;
		for (int i = 0; i < 9; i++){
			scanf("%d %d", &a, &b);
			Y += a; K += b;
		}
		if (Y > K){printf("Yonsei\n");}
		else if (Y < K){printf("Korea\n");}
		else {printf("Draw\n");}
	}
}