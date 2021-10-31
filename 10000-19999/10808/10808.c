// 10808 알파벳 개수
// https://www.acmicpc.net/problem/10808
#include <stdio.h>
#include <string.h>

int main(){
	int alpha[26] = {0, };
	char word[1000];
	scanf("%s", word);
	for (int i = 0; i < strlen(word); i++){
		alpha[word[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++){
		printf("%d ", alpha[i]);
	}
}