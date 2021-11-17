// 2563 색종이
// https://www.acmicpc.net/problem/2563
#include <stdio.h>

int main(){
	int arr[101][101] = {0, };
	int x1, y1, N, area = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d %d", &x1, &y1);
		for (int x = x1; x < x1 + 10; x++){
			for (int y = y1; y < y1 + 10; y++){
				arr[x][y] = 1;
			}
		}
	}
	for (int x = 0; x <= 100; x++){
		for (int y = 0; y <= 100; y++){
			area += arr[x][y];
		}
	}
	printf("%d", area);
}