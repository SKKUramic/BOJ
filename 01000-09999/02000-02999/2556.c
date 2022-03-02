// 2526 별 찍기 - 14
// 백준 당신은 나쁜 사람이에요.
#include <stdio.h>

int main(){
	int star;
	scanf("%d", &star);
	for (int i = 0; i < star; i++){
		for (int j = 0; j < star; j++){
			printf("*");
		}
		printf("\n");
	}
}