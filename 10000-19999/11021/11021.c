// 11021 A+B - 7
#include <stdio.h>

int main(int argc, char* argv[]) {
	int a, b, n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i, a + b);
	} 
}