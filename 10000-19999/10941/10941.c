// 10941 BASE16 디코딩
// 10940 문제와 세트입니다.
// https://www.acmicpc.net/problem/10941
#include <stdio.h>
#include <string.h>

int main(){
	int len, temp = 0;
	char word[100], answer[50];
	scanf("%s", word);
	len = strlen(word);
	for (int i = 0; i < len; i++){
		if (word[i] > '9'){
			temp = temp * 16 + (word[i] - 'A' + 10);
		}
		else {
			temp = temp * 16 + (word[i] - '0');
		}
		if (i % 2 == 1){
			answer[i / 2] = temp;
			temp = 0;
		}
	}
	answer[len / 2] = '\0';
	printf("%s", answer);
}