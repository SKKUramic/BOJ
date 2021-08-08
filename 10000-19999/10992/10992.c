// 10992 별 찍기 - 17
#include <stdio.h>

int main(){
	int star;
	scanf("%d", &star);
	for (int i = 0; i < star; i++){
		for (int j = 0; j < star - i - 1; j++){
			printf(" ");
		}
		printf("*");
		if (i == 0){
			printf("\n");
			continue;
		}
		for (int j = 0; j < 2 * i - 1; j++){
			if (i == star - 1){
				printf("*");
			}
			else {
				printf(" ");	
			}
		}
		printf("*\n");
	}
}