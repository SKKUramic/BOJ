// 2439 별 찍기 - 2
#include <stdio.h>

int main(int argc, char* argv[]) {
	int n;
	scanf("%d", &n);
	for (int i = n; i > 0; i--){
		for (int j = 0; j < i - 1; j++){
			printf(" ");
		}
		for (int k = i - 1; k < n; k++){
			printf("*");
		}
		printf("\n");
	}
}