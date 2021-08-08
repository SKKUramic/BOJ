// 2935 소음
// https://www.acmicpc.net/problem/2935
#include <stdio.h>
#include <string.h>

int main(){
	char num1[101];
	char num2[101];
	char c[2];
	int len1, len2;
	scanf("%s", num1);
	scanf("%s", c);
	scanf("%s", num2);
	len1 = strlen(num1);
	len2 = strlen(num2);
	if (c[0] == '*'){
		printf("1");
		for (int i = 1; i < len1; i++){
			printf("%c", num1[i]);
		}
		for (int i = 1; i < len2; i++){
			printf("%c", num2[i]);
		}
	}
	else if (c[0] == '+'){
		if (len1 > len2){
			for (int i = 0; i < len1; i++){
				if (i >= len1 - len2){
					printf("%d", (num1[i] - '0') + (num2[i - (len1 - len2)] - '0'));
				}
				else {
					printf("%c", num1[i]);
				}
			}
		}
		else {
			for (int i = 0; i < len2; i++){
				if (i >= len2 - len1){
					printf("%d", (num1[i - (len2 - len1)] - '0') + (num2[i] - '0'));
				}
				else {
					printf("%c", num2[i]);
				}
			}
		}
	}
}