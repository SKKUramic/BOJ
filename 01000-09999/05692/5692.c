// 5692 팩토리얼 진법
// https://www.acmicpc.net/problem/5692
#include <stdio.h>
#include <string.h>

int factorial[5] = {1, 2, 6, 24, 120}; // 1!, 2!, 3!, 4!, 5!

int main(){
	char number[5];
	int len, answer;
	scanf("%s", number);
	len = strlen(number);
	while (number[len - 1] != '0' || len != 1){
		answer = 0;
		for (int i = 0; i < len; i++){
			answer += (number[i] - '0') * factorial[len - i - 1];
		}
		printf("%d\n", answer);
		scanf("%s", number);
		len = strlen(number);
	}
}