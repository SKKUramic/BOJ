// 13225 Divisors
// https://www.acmicpc.net/problem/13225
#include <stdio.h>

int divisors_count(int k){
	if (k == 1){return 1;}
	int count = 0;
	for (int i = 2; i * i <= k; i++){
		if (k % i == 0){
			count++;
			if (i * i != k){
				count++;
			}
		}
	}
	return count + 2;
}

int main(){
	int test, num;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d", &num);
		printf("%d %d\n", num, divisors_count(num));
	}
}