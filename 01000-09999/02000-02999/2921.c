// 2921 도미노
// https://www.acmicpc.net/problem/2921
#include <stdio.h>

int main(){
	int N, sum = 0;
	scanf("%d", &N);
	for (int i = 0; i <= N; i++){
		for (int j = i; j <= N; j++){
			sum += (i + j);
		}
	}
	printf("%d", sum);
}