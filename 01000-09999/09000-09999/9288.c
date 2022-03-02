// 9288 More Dice
// https://www.acmicpc.net/problem/9288
#include <stdio.h>

int main(){
	int TC, sum, cnum = 1;
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d", &sum);
		printf("Case %d:\n", cnum++);
		for (int i = 1; i <= 6; i++){
			for (int j = 1; j <= 6; j++){
				if (i + j == sum && i <= j){
					printf("(%d,%d)\n", i, j);
				}
			}
		}
	}
}