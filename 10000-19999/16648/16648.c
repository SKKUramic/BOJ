// 16648 Accumulator Battery
// https://www.acmicpc.net/problem/16648
#include <stdio.h>

int main(){
	int t, p;
	double answer;
	scanf("%d %d", &t, &p);
	if (p >= 20){
		answer = ((double)t / (double)(100 - p)) * (double)(p + 20);
	}
	else if (p < 20){
		answer = ((double)t / (double)(80 + (20 - p) * 2)) * (double)(p * 2);
	}
	printf("%.6lf", answer);
}