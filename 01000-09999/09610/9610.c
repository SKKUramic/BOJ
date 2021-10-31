// 9610 사분면
// https://www.acmicpc.net/problem/9610
#include <stdio.h>

int main(){
	int N, x, y;
	int Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0, Axis = 0;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d %d", &x, &y);
		if (x == 0 || y == 0){Axis++;}
		else if (x > 0 && y > 0){Q1++;}
		else if (x < 0 && y > 0){Q2++;}
		else if (x < 0 && y < 0){Q3++;}
		else if (x > 0 && y < 0){Q4++;}
	}
	printf("Q1: %d\n", Q1);
	printf("Q2: %d\n", Q2);
	printf("Q3: %d\n", Q3);
	printf("Q4: %d\n", Q4);
	printf("AXIS: %d", Axis);
}