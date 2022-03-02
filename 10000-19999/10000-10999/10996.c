//10996 별 찍기 - 21
#include <stdio.h>

int main(){
	int star;
	scanf("%d", &star);
	if (star == 1){
		printf("*\n");
		return 0;
	}
	for (int i = 0; i < 2 * star; i++){
		if (i % 2 == 1){
			for (int j = 0; j < star; j++){
				if (j % 2 == 0){
					printf(" ");
				}
				else {
					printf("*");
				}
			}
		}
		else {
			for (int j = 0; j < star; j++){
				if (j % 2 == 0){
					printf("*");
				}
				else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}