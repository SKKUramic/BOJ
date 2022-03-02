// 2566 최댓값
// https://www.acmicpc.net/problem/2566
#include <stdio.h>

int main(){
	int arr;
	int max = -1, max_x, max_y;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			scanf("%d", &arr);
			if (arr > max){
				max = arr;
				max_y = i + 1;
				max_x = j + 1;
			}
		}
	}
	printf("%d\n%d %d", max, max_y, max_x);
}