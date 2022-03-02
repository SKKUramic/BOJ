// 10953 A+B - 6
#include <stdio.h>

int main(){
	int test, a, b;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}
}