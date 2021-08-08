// 10039 평균 점수
// https://www.acmicpc.net/problem/10039
#include <stdio.h>

int main(){
	int arr[5];
	for (int i = 0; i < 5; i++){
		scanf("%d", &arr[i]);
		if (arr[i] < 40){arr[i] = 40;}
	}
	printf("%d", (arr[0] + arr[1] + arr[2] + arr[3] + arr[4]) / 5);
}