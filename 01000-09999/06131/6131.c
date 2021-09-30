// 6131 완전 제곱수
// https://www.acmicpc.net/problem/6131
#include <stdio.h>

int main(){
	int N, count = 0;
	scanf("%d", &N);
	for (int a = 1; a <= 500; a++){
		for (int b = 1; b <= a; b++){
			if (a * a - b * b == N){
				count++;
				break;
			}
		}
	}
	printf("%d", count);
}