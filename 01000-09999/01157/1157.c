// 1157 단어 공부
// https://www.acmicpc.net/problem/1157
#include <stdio.h>
#include <string.h>

int main(){
	char word[1000000];
	char c;
	int alphabet[26] = {0, };
	int len, i, index, max = -1;
	scanf("%s", word);
	len = strlen(word);
	for (int i = 0; i < len; i++){
		if (word[i] < 91){
			alphabet[word[i] - 65]++;
		}
		else {
			alphabet[word[i] - 97]++;
		}
	}
	for (i = 0; i < 26; i++){
		if (alphabet[i] > max){
			max = alphabet[i];
			index = i;
			c = 65 + i;
		}
	}
	for (i = 0; i < 26; i++){
		if (alphabet[i] == max && index != i){
			c = '?';
		}
	}
	printf("%c", c);
}