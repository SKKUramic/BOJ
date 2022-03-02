// 2444 별 찍기 - 7
#include <stdio.h>

int main(){
	int star;
	scanf("%d", &star);
	for (int i = 0; i < star; i++){
		for (int j = 0; j < star - i - 1; j++){
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++){
			printf("*");
		}
		printf("\n");
	}
	star--;
	for (int i = 0; i < star; i++){
		for (int j = 0; j < i + 1; j++){
			printf(" ");
		}
		for (int k = 0; k < 2 * (star - i) - 1; k++){
			printf("*");
		}
		printf("\n");
	}
}