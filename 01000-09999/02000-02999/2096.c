// 2096 내려가기
// https://www.acmicpc.net/problem/2096
#include <stdio.h>

int max[3] = {0, 0, 0};
int max_temp[3];
int min[3] = {0, 0, 0};
int min_temp[3];
int temp[3];

int ret_max(int a, int b, int c){
	if (a > b){
		if (a > c){
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b > c){
			return b;
		}
		else {
			return c;
		}
	}
}

int ret_min(int a, int b, int c){
	if (a < b){
		if (a < c){
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b < c){
			return b;
		}
		else {
			return c;
		}
	}
}

int main(){
	int N;
	scanf("%d", &N);
	scanf("%d %d %d", &max[0], &max[1], &max[2]);
	min[0] = max[0]; min[1] = max[1]; min[2] = max[2];
	for (int i = 2; i <= N; i++){
		scanf("%d %d %d", &temp[0], &temp[1], &temp[2]);
		max_temp[0] = ret_max(max[0] + temp[0], max[1] + temp[0], 0);
		max_temp[1] = ret_max(max[0] + temp[1], max[1] + temp[1], max[2] + temp[1]);
		max_temp[2] = ret_max(max[1] + temp[2], max[2] + temp[2], 0);
		min_temp[0] = ret_min(min[0] + temp[0], min[1] + temp[0], 1000000);
		min_temp[1] = ret_min(min[0] + temp[1], min[1] + temp[1], min[2] + temp[1]);
		min_temp[2] = ret_min(min[1] + temp[2], min[2] + temp[2], 1000000);
		for (int k = 0; k < 3; k++){
			max[k] = max_temp[k];
			min[k] = min_temp[k];
		}
	}
	printf("%d %d", ret_max(max[0], max[1], max[2]), ret_min(min[0], min[1], min[2]));
}