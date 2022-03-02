//18408 3 つの整数 (Three Integers)
#include <stdio.h>

int main(){
	int one_count = 0, two_count = 0;
	int a;
	for (int i = 0; i < 3; i++){
		scanf("%d", &a);
		if (a == 1){
			one_count++;
		}
		else if (a == 2){
			two_count++;
		}
	}
	if (one_count > two_count){
		printf("1");
	}
	else {
		printf("2");
	}
}