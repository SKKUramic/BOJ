// 2669 직사각형 네개의 합집합의 면적 구하기
// https://www.acmicpc.net/problem/2669
#include <stdio.h>

int main(){
	int arr[101][101] = {0, };
	int x1, x2, y1, y2, area = 0;
	for (int i = 0; i < 4; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int x = x1; x < x2; x++){
			for (int y = y1; y < y2; y++){
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