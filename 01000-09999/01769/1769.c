// 1769 3의 배수
// https://www.acmicpc.net/problem/1769
#include <stdio.h>
#include <string.h>

char num[1000001];

int main(){
	int number = 0, count = 0, number_temp, temp;
	scanf("%s", num);
	if (strlen(num) == 1){
		printf("0\n");
		if ((num[0] - '0') % 3 == 0){
			printf("YES");
		}
		else {
			printf("NO");
		}
		return 0;
	}
	int len = strlen(num);
	for (int i = 0; i < len; i++){
		number += (num[i] - '0');
	}
	count++;
	while (number >= 10){
		temp = 0;
		number_temp = number;
		while (number_temp > 0){
			temp += number_temp % 10;
			number_temp /= 10;
		}
		number = temp;
		count++;
	}
	printf("%d\n", count);
	if (number % 3 == 0){
		printf("YES");
	}
	else {
		printf("NO");
	}
}