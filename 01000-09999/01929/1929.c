// 1929 소수 구하기
#include <stdio.h>

int main(){
	int sieve[1000001] = {0, };
	int start, end, index = 2, k = 2;
	sieve[0] = -1; sieve[1] = -1;
	scanf("%d %d", &start, &end);
	for (int i = 2; i <= end; i++){
		if (sieve[i] == 0){
			sieve[i] = 1;
			while (i * k <= end){
				sieve[i * k] = -1;
				k++;
			}
			k = 2;
		}
	}
	for (int i = start; i <= end; i++){
		if (sieve[i] == 1){
			printf("%d\n", i);
		}
	}
}