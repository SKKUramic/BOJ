// 10809 알파벳 찾기
#include <stdio.h>
#include <string.h>

int main(){
	int alpha[26];
	int len, index;
	char word[100];
	for (int i = 0; i < 26; i++){
		alpha[i] = -1;
	}
	scanf("%s", word);
	len = strlen(word);
	for (int x = 0; x < len; x++){
		index = word[x] - 97;
		if (alpha[index] == -1){
			alpha[index] = x;
		}
	}
	for (int y = 0; y < 26; y++){
		printf("%d ", alpha[y]);
	}
}