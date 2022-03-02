// 10872 팩토리얼
#include <stdio.h>

int factorial(int x){
	if (x == 0 || x == 1){return 1;}
	else {
		return x * factorial(x - 1);
	}
}

int main(){
	int N;
	scanf("%d", &N);
	printf("%d", factorial(N));
}