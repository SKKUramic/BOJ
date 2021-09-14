// 2789 유학 금지
// https://www.acmicpc.net/problem/2789
#include <stdio.h>
#include <string.h>

int main(){
	int can;
	char NO[9] = "CAMBRIDGE";
	char word[101];
	scanf("%s", word);
	for (int i = 0; i < strlen(word); i++){
		can = 1;
		for (int j = 0; j < 9; j++){
			if (word[i] == NO[j]){
				can = 0;
			}
		}
		if (can) {printf("%c", word[i]);}
	}
}