// 2739 구구단
#include <stdio.h>

int main(int argc, char* argv[]) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < 10; i++){
		printf("%d * %d = %d\n", n, i, n*i);
	} 
}