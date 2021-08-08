// 2438 별 찍기 - 1
#include <stdio.h>

int main(int argc, char* argv[]) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < i; j++){
			printf("*");
		}
		printf("\n");
	}
}