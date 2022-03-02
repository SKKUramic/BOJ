// 2445 별 찍기 - 8
#include <stdio.h>

int main(){
	int star;
	scanf("%d", &star);
	for (int i = 1; i <= star; i++){
		for (int j = 0; j < i; j++){
			printf("*");
		}
		for (int k = 0; k < 2 * (star - i); k++){
			printf(" ");
		}
		for (int j = 0; j < i; j++){
			printf("*");
		}
		printf("\n");
	}
	star--;
	for (int i = star; i >= 1; i--){
		for (int j = 0; j < i; j++){
			printf("*");
		}
		for (int k = 0; k < 2 * (star - i + 1); k++){
			printf(" ");
		}
		for (int j = 0; j < i; j++){
			printf("*");
		}
		printf("\n");
	}
}