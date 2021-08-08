//1316 - 그룹 단어 체크
#include <stdio.h>
#include <string.h>

int main(){
	int N, len, count = 0;
	char word[100];
	int alphabet[26] = {0, };
	char checker = '?';
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%s", word);
		len = strlen(word);
		count++;
		//printf("before check: %d\n", count);
		for (int j = 0; j < len; j++){
			if (alphabet[word[j] - 'a'] != 0 && word[j] != checker){
				count--;
				break;
			}
			alphabet[word[j] - 'a']++;
			checker = word[j];
		}
		for (int j = 0; j < 26; j++){alphabet[j] = 0;}
		for (int j = 0; j < len; j++){word[j] = ' ';}
		checker = '?';
		//printf("after check: %d\n\n", count);
	}
	printf("%d", count);
}