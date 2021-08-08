// 2609 최대공약수와 최소공약수
#include <stdio.h>

int prime[2000] = {0, };

int main(){
	int sieve[10001] = {0, };
	int num1, num2, index = 2, k = 2, prime_index = 0;
	int GCF = 1, LCM = 1;
	sieve[0] = -1; sieve[1] = -1;
	scanf("%d %d", &num1, &num2);
	for (int i = 2; i <= num2; i++){
		if (sieve[i] == 0){
			prime[prime_index++] = i;
			sieve[i] = 1;
			while (i * k <= num2){
				sieve[i * k] = -1;
				k++;
			}
			k = 2;
		}
	}
	prime_index = 0;
	k = prime[prime_index++];
	while (num1 >= k && num2 >= k && k != 0){
		while (num1 % k == 0 && num2 % k == 0){
			num1 /= k;
			num2 /= k;
			GCF *= k;
		}
		k = prime[prime_index++];
	}
	LCM = num1 * num2 * GCF;
	printf("%d\n%d", GCF, LCM);
}