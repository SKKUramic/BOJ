// 2576 홀수
// https://www.acmicpc.net/problem/2576
#include <stdio.h>

int main(){
	int num, min = 99999, sum = 0;
	for (int i = 0; i < 7; i++){
		scanf("%d", &num);
		if (num % 2 == 1){
			sum += num;
			if (num < min){min = num;}
		}
	}
	if (sum == 0){printf("-1");}
	else {printf("%d\n%d", sum, min);}
}