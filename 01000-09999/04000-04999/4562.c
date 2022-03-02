// 4562 No Brainer
// https://www.acmicpc.net/problem/4562
#include <stdio.h>

int main(){
	int n, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		if (x < y){printf("NO BRAINS\n");}
		else {printf("MMM BRAINS\n");}
	}
}