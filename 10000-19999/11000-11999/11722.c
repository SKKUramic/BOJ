// 11722 가장 긴 감소하는 부분 수열
// https://www.acmicpc.net/problem/11722
#include <stdio.h>

int arr[1001] = {0, };
int LDS[1001] = {1111, };
int IDX[1001] = {0, };
int answer[1001];

int proper_idx(int left, int right, int input){
	int middle;
	while (left < right){
		middle = (left + right) / 2;
		if (LDS[middle] <= input){right = middle;}
		else {left = middle + 1;}
	}
	return left;
}

int main(){
	int N, len = 1, idx, ans_len;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		if (LDS[len - 1] > arr[i]){
			LDS[len++] = arr[i];
		}
		else{
			LDS[proper_idx(0, len, arr[i])] = arr[i];
		}
	}
	ans_len = len - 1;
	printf("%d", ans_len);
}