// 4948 베르트랑 공준
#include <stdio.h>

int main(){
	int sieve[1000001] = {0, };
	int test[123456] = {0, };
	int n = -1, index = 2, k = 2, x = 0;
	int start, end, count = 0;
	sieve[0] = -1; sieve[1] = -1;
	while (n != 0){
		scanf("%d", &n);
		test[x++] = n;
	}
	x--;
	for (int i = 2; i < 246913; i++){ // 246912 = 123456 * 2
		if (sieve[i] == 0){
			sieve[i] = 1;
			while (i * k <= 246913){
				sieve[i * k] = -1;
				k++;
			}
			k = 2;
		}
	}
	for (int a = 0; a < x; a++){
		start = test[a] + 1; end = 2 * test[a];
		// printf("start: %d, end: %d\n", start, end);
		for (int i = start; i <= end; i++){
			if (sieve[i] == 1){
				count++;
			}
		}
		printf("%d\n", count);
		count = 0;
	}
}