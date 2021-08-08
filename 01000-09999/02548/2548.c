// 2548 대표 자연수
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, x = 0, answer = 10001, differ, sum = 0, SUM = 200000002;
	scanf("%d", &N);
	int *number = (int *)malloc(sizeof(int) * N);
	for (int a = 0; a < N; a++) {
		scanf("%d", &number[a]);
	}
	for (int y = 0; y < N; y++) {
		while (sum <= SUM && x < N) {
			differ = (number[x] > number[y]) ? (number[x] - number[y]) : (number[y] - number[x]);
			sum += differ;
			x++;
		}
		if ((sum < SUM && x == N) || (sum == SUM && number[y] < answer && x == N)) {
			SUM = sum;
			answer = number[y];
		}
		sum = 0;
		x = 0;
	}
	printf("%d", answer);
	free(number);
}