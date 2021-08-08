// 9020 골드바흐의 추측
#include <stdio.h>

int main(){
	int sieve[10001] = {0, };
	int test, index = 2, k = 2;
	int num, gold, bach;
	sieve[0] = -1; sieve[1] = -1;
	scanf("%d", &test);
	//scanf("%d %d", &start, &end);
	for (int i = 2; i <= 10000; i++){
		if (sieve[i] == 0){
			sieve[i] = 1;
			while (i * k <= 10000){
				sieve[i * k] = -1;
				k++;
			}
			k = 2;
		}
	}
	for (int i = 0; i < test; i++){
		scanf("%d", &num);
		gold = num / 2; bach = num / 2;
		while (sieve[gold] != 1 || sieve[bach] != 1){
			gold--; bach++;
		}
		printf("%d %d\n", gold, bach);
	}
}