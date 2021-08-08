// 5617 問題 1
// https://www.acmicpc.net/problem/5617
// 주어진 삼각형들이 예각, 직각, 둔각 삼각형 중 무엇인지 알아낼 수 있으면 됩니다.
#include <stdio.h>

int main(){
	int side[3], side_sum, temp;
	int triangle[4] = {0, }; // 삼각형, 직각삼각형, 예각삼각형, 둔각삼각형
	while (1){
		side_sum = 0;
		scanf("%d %d %d", &side[0], &side[1], &side[2]);
		side_sum = side[0] + side[1] + side[2];
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 2; j++){
				if (side[j] < side[j + 1]){
					temp = side[j];
					side[j] = side[j + 1];
					side[j + 1] = temp;
				}
			}
		}
		if (side[0] * 2 >= side_sum){break;}
		triangle[0]++;
		if (side[0] * side[0] > side[1] * side[1] + side[2] * side[2]){ // 둔각삼각형
			triangle[3]++;
		}
		else if (side[0] * side[0] < side[1] * side[1] + side[2] * side[2]){ // 예각삼각형
			triangle[2]++;
		}
		else {
			triangle[1]++;
		}
	}
	printf("%d %d %d %d", triangle[0], triangle[1], triangle[2], triangle[3]);
}