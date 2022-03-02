// 2018 수들의 합 5
// https://www.acmicpc.net/problem/2018
#include <stdio.h>

int main(){
	int left = 1, right = 1, count = 0, sum = 0, N;
	scanf("%d", &N);
	while (left <= right && right <= N + 1){
		if (sum > N){
			sum -= left;
			left++;
		}
		else if (sum < N){
			sum += right;
			right++;
		}
		else {
			count++;
			sum += right;
			right++;
		}
	}
	printf("%d", count);
}