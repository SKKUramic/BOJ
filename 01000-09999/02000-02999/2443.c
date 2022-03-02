// 2443 별 찍기 - 6
#include <stdio.h>

int main(){
	int star;
	scanf("%d", &star);
	for (int i = 0; i < star; i++){
		for (int j = 0; j < i; j++){
			printf(" ");
		}
		for (int k = 0; k < 2 * (star - i) - 1; k++){
			printf("*");
		}
		printf("\n");
	}
}