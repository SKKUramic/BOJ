//1009 분산처리
#include <stdio.h>

int main(){
	int test, a, b, temp;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d %d", &a, &b);
		a = a % 10;
		temp = a;
		if (a == 0){
			printf("10\n");
		}
		else if (a == 1 || a == 5 || a == 6){
			printf("%d\n", a);
		}
		else if (a == 4 || a == 9){
			b %= 2;
			if (b == 0){
				printf("%d\n", (a * a) % 10);
			}
			else {
				printf("%d\n", a);
			}
		}
		else if (a == 2 || a == 3 || a == 7 || a == 8){
			b %= 4;
			if (b == 0){
				b = 4;
			}
			for (int i = 0; i < b - 1; i++){
				//printf("%d ", a);
				a *= temp;
				a %= 10;
			}
			printf("%d\n", a);
		}
	}
	return 0;
}