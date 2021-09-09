// 14003 가장 긴 증가하는 부분 수열 5
// https://www.acmicpc.net/problem/14003
#include <stdio.h>

int arr[1000001] = {0, };
int LIS[1000001] = {-1111111111, };
int IDX[1000001] = {0, };
int answer[1000001];

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
	int N, len = 1, idx, ans_len;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		if (LIS[len - 1] < arr[i]){
			IDX[i] = len;
			LIS[len++] = arr[i];
		}
		else{
			idx = proper_idx(0, len, arr[i]);
			IDX[i] = idx;
			LIS[idx] = arr[i];
		}
	}
	ans_len = len - 1;
	idx = N - 1;
	printf("%d\n", ans_len);
	while (ans_len > 0){
		if (IDX[idx] == ans_len){
			answer[ans_len--] = arr[idx];
		}
		idx--;
	}
	for (int i = 1; i < len; i++){ 
		printf("%d ", answer[i]);
	}
}