// 1475 방번호
// https://www.acmicpc.net/problem/1475
#include <stdio.h>

int number_need[10] = {0, };

int main(){
	int N, num, answer = -1, answer_idx = -1;
	scanf("%d", &N);
	if (N == 0){
		printf("1");
		return 0;
	}
	while (N){
		num = N % 10;
		if (num == 9){num = 6;}
		number_need[num]++;
		N /= 10;
	}
	if (number_need[6] % 2 == 0){
		number_need[6] /= 2;
	}
	else {
		number_need[6] = (number_need[6] + 1) / 2;
	}
	for (int i = 0; i < 9; i++){
		if (answer < number_need[i]){
			answer = number_need[i];
		}
	}
	printf("%d", answer);
}