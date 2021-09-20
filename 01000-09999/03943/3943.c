// 3943 헤일스톤 수열
// https://www.acmicpc.net/problem/3943
#include <stdio.h>

int main(){
	int n, max, TC;
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d", &n);
		max = n;
		while (n != 1){
			if (n % 2 == 0) {n /= 2;}
			else {n = 3 * n + 1;}
			if (n > max){max = n;}
		}
		printf("%d\n", max);
	}
}