// 10419 지각
// https://www.acmicpc.net/problem/10419
#include <stdio.h>

int main(){
	int TC, num;
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d", &num);
		for (int i = 1; i < 1000; i++){
			if (i + i * i > num){
				printf("%d\n", i - 1);
				break;
			}
			else if (i + i * i == num){
				printf("%d\n", i);
				break;
			}
		}
	}
}