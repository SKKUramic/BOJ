// 2721 삼각수의 합
// https://www.acmicpc.net/problem/2721
#include <stdio.h>

int main(){
	int TC, n, sum;
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d", &n);
		sum = 0;
		for (int i = 1; i <= n; i++){
			sum += (i * (i + 1) * (i + 2)) / 2;
		}
		printf("%d\n", sum);
	}
}