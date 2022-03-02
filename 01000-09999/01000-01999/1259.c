// 1259 팰린드롬수
// https://www.acmicpc.net/problem/1259
#include <stdio.h>
#include <string.h>

int main(){
	char number[10];
	int len, flags = 1;
	while (1){
		scanf("%s", number);
		if (number[0] == '0'){break;}
		len = strlen(number);
		for (int i = 0; i < len / 2; i++){
			if (number[i] != number[len - 1 - i]){
				flags = 0;
				break;
			}
		}
		if (flags){
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
		flags = 1;
	}
	return 0;
}