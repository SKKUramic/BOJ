// 7600 문자가 몇갤까
// https://www.acmicpc.net/problem/7600
#include <stdio.h>
#include <string.h>

char sentence[300];
int alphabet[26] = {0, };

int main(){
	int len, count;
	while (1){
		count = 0;
		scanf(" %[^\n]s", sentence);
		len = strlen(sentence);
		if (len == 1 && sentence[0] == '#'){break;}
		for (int i = 0; i < len; i++){
			if (sentence[i] >= 'a' && sentence[i] <= 'z'){
				alphabet[sentence[i] - 'a']++;
			}
			else if (sentence[i] >= 'A' && sentence[i] <= 'Z'){
				alphabet[sentence[i] - 'A']++;
			}
		}
		for (int i = 0; i < 26; i++){
			if (alphabet[i] != 0){count++;}
			alphabet[i] = 0;
		}
		printf("%d\n", count);
		scanf("%[^\n]s", sentence);
	}
}