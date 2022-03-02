// 2523 별 찍기 - 13
#include <stdio.h>

int main(){
	int star;
	scanf("%d", &star);
	for (int i = 0; i < 2 * star - 1; i++){
		if (i < star){
			for (int j = 0; j <= i; j++){
				printf("*");
			}
			printf("\n");
		}
		else {
			for (int j = 0; j <= 2 * star - i - 2; j++){
				printf("*");
			}
			printf("\n");
		}
	}
}