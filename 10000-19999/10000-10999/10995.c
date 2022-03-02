// 10995 별 찍기 - 20
#include <stdio.h>

int main(){
	int star;
	scanf("%d", &star);
	if (star == 1){printf("*\n"); return 0;}
	for (int i = 0; i < star; i++){
		if (i % 2 == 0){
			for (int j = 0; j < 2 * star; j++){
				if (j % 2 == 0){
					printf("*");
				}
				else{
					printf(" ");
				}
			}
		}
		else {
			for (int j = 0; j < 2 * star + 1; j++){
				if (j % 2 == 0){
					printf(" ");
				}
				else {
					printf("*");
				}
			}
		}
		printf("\n");
	}
}