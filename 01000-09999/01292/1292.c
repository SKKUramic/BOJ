// 1292 쉽게 푸는 문제
// https://www.acmicpc.net/problem/1292
#include <stdio.h>

int main(){
	int sum = 0, idx = 1;
	int A, B;
	scanf("%d %d", &A, &B);
	for (int n = 1; n < 1000; n++){
		for (int k = 1; k <= n; k++){
			if (A <= idx && idx <= B){
				sum += n;
			}
			idx++;
		}
		if (idx > B){break;}
	}
	printf("%d", sum);
}