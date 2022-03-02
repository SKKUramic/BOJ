// 10991 별 찍기 - 16
#include <stdio.h>

int main(){
	int star;
	scanf("%d", &star);
	for (int i = 0; i < star; i++){
		for (int j = 0; j < star - i - 1; j++){
			printf(" ");
		}
		//printf("*");
		if (i == 0){
			printf("*\n");
			continue;
		}
		for (int j = 0; j <= 2 * i + 1; j++){
			if (j % 2 == 0){
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}