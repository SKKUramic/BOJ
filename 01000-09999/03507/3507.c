// 3507 Automated Telephone Exchange
// https://www.acmicpc.net/problem/3507
#include <stdio.h>

int main(){
	int N, count = 0;
	scanf("%d", &N);
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if (i + j == N){
				count++;
			}
		}
	}
	printf("%d", count);
}