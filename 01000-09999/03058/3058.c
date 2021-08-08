// 3058 짝수를 찾아라
// https://www.acmicpc.net/problem/3058
#include <stdio.h>

int main(){
	int T, sum, min, num;
	scanf("%d", &T);
	while (T-- > 0){
		min = 1000000;
		sum = 0;
		for (int i = 0; i < 7; i++){
			scanf("%d", &num);
			if (num % 2 == 0){
				sum += num;
				if (num < min){
					min = num;
				}
			}
		}
		printf("%d %d\n", sum, min);
	}
}