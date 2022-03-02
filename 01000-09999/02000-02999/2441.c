// 2441 별 찍기 - 4
#include <stdio.h>

int main(){
	int star;
	scanf("%d", &star);
	for (int i = 0; i < star; i++){
		for (int j = 0; j < i; j++){
			printf(" ");
		}
		for (int k = i; k < star; k++){
			printf("*");
		}
		printf("\n");
	}
}