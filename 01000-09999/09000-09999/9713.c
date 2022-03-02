// 9713 Sum of Odd Sequence
#include <stdio.h>

int main(){
	int test, odd, sum = 0;
	scanf("%d", &test);
	for (int a = 0; a < test; a++){
		scanf("%d", &odd);
		for (int i = 1; i <= odd; i += 2){
			sum += i;
		}
		printf("%d\n", sum);
		sum = 0;
	}
}