// 14563 완전수
// https://www.acmicpc.net/problem/14563
#include <stdio.h>

int main(){
	int TC, n, sum;
	scanf("%d", &TC);
	while (TC-- > 0){
		sum = 0;
		scanf("%d", &n);
		if (n == 1){
			printf("Deficient\n");
		}
		else {
			for (int i = 1; i < n; i++){
				if (n % i == 0){sum += i;}
			}
			if (sum > n){printf("Abundant\n");}
			else if (sum < n){printf("Deficient\n");}
			else {printf("Perfect\n");}
		}
	}
}