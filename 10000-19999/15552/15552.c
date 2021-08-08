// 15552 빠른 A+B
#include <stdio.h>

int main(int argc, char* argv[]) {
	int a, b, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	} 
}