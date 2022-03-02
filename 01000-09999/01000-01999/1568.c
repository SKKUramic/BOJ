// 1568 새
// https://www.acmicpc.net/problem/1568
#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	int bird = 1, second = 1;
	while (1){
		if (N < bird){
			bird = 1;
		}
		N -= bird;
		if (N == 0){break;}
		second++; bird++;
	}
	printf("%d", second);
}