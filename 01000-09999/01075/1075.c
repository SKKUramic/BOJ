// 1075 나누기
#include <stdio.h>

int main(){
	long int N, F, temp;
	scanf("%ld", &N);
	scanf("%ld", &F);
	N = (N / 100) * 100;
	for (int i = 0; i < 100; i++){
		if ((N + i) % F == 0){
			printf("%02d", i);
			break;
		}
	}
}