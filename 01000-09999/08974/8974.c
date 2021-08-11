// 8974 희주의 수학시험
// https://www.acmicpc.net/problem/8974
#include <stdio.h>

int main(){
	int A, B, idx = 1, sum = 0;
	scanf("%d %d", &A, &B);
	for (int x = 1; idx <= B; x++){
		for (int y = 1; y <= x; y++){
			if (idx >= A && idx <= B){
				sum += x;
			}
			idx++;
		}
	}
	printf("%d", sum);
}