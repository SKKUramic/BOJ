// 17608 막대기
// https://www.acmicpc.net/problem/17608
#include <stdio.h>

int arr[100001] = {0, };

int main(){
	int N, stick = 0, cnt = 0;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d", &arr[n]);
	}
	for (int i = N - 1; i >= 0; i--){
		if (stick < arr[i]){
			stick = arr[i];
			cnt++;
		}
	}
	printf("%d", cnt);
}