// 10940 BASE16 인코딩
// 10941 문제와 세트입니다.
// https://www.acmicpc.net/problem/10940
#include <stdio.h>
#include <string.h>

int main(){
	int len, temp = 0;
	char word[100], answer[200];
	scanf("%s", word);
	len = strlen(word);
	for (int i = 0; i < len; i++){
		temp = word[i] / 16;
		if (temp > 9){
			temp = temp - 10 + 'A'; 
		}
		else {
			temp = temp + '0';
		}
		answer[2 * i] = temp;
		temp = word[i] % 16;
		if (temp > 9){
			temp = temp - 10 + 'A'; 
		}
		else {
			temp = temp + '0';
		}
		answer[2 * i + 1] = temp;
	}
	answer[2 * len] = '\0';
	printf("%s", answer);
}