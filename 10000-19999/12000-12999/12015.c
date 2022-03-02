// 12015 가장 긴 증가하는 부분 수열 2
// https://www.acmicpc.net/problem/12015
// 이게 왜 되지??
#include <stdio.h>

int LIS[1000001] = {-1111111111, };

int proper_idx(int left, int right, int input){
	int middle;
	while (left < right){
		middle = (left + right) / 2;
		if (LIS[middle] >= input){right = middle;}
		else {left = middle + 1;}
	}
	return left;
}

int main(){
	int N, len = 1, num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		if (LIS[len - 1] < num){
			LIS[len++] = num;
		}
		else{
			LIS[proper_idx(0, len, num)] = num;
		}
	}
	printf("%d", len - 1);
}