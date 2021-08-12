// 2592 대표값
// https://www.acmicpc.net/problem/2592
#include <stdio.h>

int main(){
	int sum = 0, wow = -1, num;
	int arr[10];
	int visit[101] = {0, };
	for (int i = 0; i < 10; i++){
		scanf("%d", &arr[i]);
		sum += (arr[i] / 10);
		visit[arr[i] / 10]++;
	}
	for (int i = 0; i <= 100; i++){
		if (wow < visit[i]){
			wow = visit[i];
			num = i * 10;
		}
	}
	printf("%d\n%d", sum, num);
}