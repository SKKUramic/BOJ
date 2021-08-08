// 10769 행복한지 슬픈지
// https://www.acmicpc.net/problem/10769
#include <stdio.h>
#include <string.h>

int main(){
	int len;
	int sad = 0, happy = 0;
	char text[300];
	scanf("%[^\n]s", text);
	len = strlen(text);
	for (int i = 0; i < len - 2; i++){
		if (text[i] == ':' && text[i + 1] == '-'){
			if (text[i + 2] == '('){
				sad++;
			}
			else if (text[i + 2] == ')'){
				happy++;
			}
		}
	}
	if (sad == 0 && happy == 0){
		printf("none");
	}
	else if (sad > happy){
		printf("sad");
	}
	else if (sad < happy){
		printf("happy");
	}
	else {
		printf("unsure");
	}
}