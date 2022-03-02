// 1284 집 주소
// https://www.acmicpc.net/problem/1284
#include <stdio.h>

int main(){
	int N, sum;
	scanf("%d", &N);
	while (N != 0){
		sum = 0;
		while (N > 0){
			sum++;
			if (N % 10 == 1){
				sum += 2;
			}
			else if (N % 10 == 0){
				sum += 4;
			}
			else {
				sum += 3;
			}
			N /= 10;
		}
		sum++;
		printf("%d\n", sum);
		scanf("%d", &N);
	}
}