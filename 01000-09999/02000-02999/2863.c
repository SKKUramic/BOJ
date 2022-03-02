// 2863 이게 분수?
// https://www.acmicpc.net/problem/2863
#include <stdio.h>

int main(){
	double arr[2][2];
	double max = -1.0;
	int index;
	scanf("%lf %lf", &arr[0][0], &arr[0][1]);
	scanf("%lf %lf", &arr[1][0], &arr[1][1]);
	if (arr[0][0] / arr[1][0] + arr[0][1] / arr[1][1] > max){
		max = arr[0][0] / arr[1][0] + arr[0][1] / arr[1][1];
		index = 0;
	}
	if (arr[1][0] / arr[1][1] + arr[0][0] / arr[0][1] > max){
		max = arr[1][0] / arr[1][1] + arr[0][0] / arr[0][1];
		index = 1;
	}
	if (arr[1][1] / arr[0][1] + arr[1][0] / arr[0][0] > max){
		max = arr[1][1] / arr[0][1] + arr[1][0] / arr[0][0];
		index = 2;
	}
	if (arr[0][1] / arr[0][0] + arr[1][1] / arr[1][0] > max){
		max = arr[0][1] / arr[0][0] + arr[1][1] / arr[1][0];
		index = 3;
	}
	printf("%d", index);
}