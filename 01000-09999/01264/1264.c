// 1264 모음의 개수
// https://www.acmicpc.net/problem/1264
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int len, vowel_count;
	char sentence[300];
	while (1){
		scanf(" %[^\n]s", sentence);	
		len = strlen(sentence);
		if (len == 1 && sentence[0] == '#'){
			break;
		}
		vowel_count = 0;
		for (int i = 0; i < len; i++){
			if (sentence[i] == 'A' || sentence[i] == 'a'){
				vowel_count++;
			}
			else if (sentence[i] == 'E' || sentence[i] == 'e'){
				vowel_count++;
			}
			else if (sentence[i] == 'I' || sentence[i] == 'i'){
				vowel_count++;
			}
			else if (sentence[i] == 'O' || sentence[i] == 'o'){
				vowel_count++;
			}
			else if (sentence[i] == 'U' || sentence[i] == 'u'){
				vowel_count++;
			}
		}
		printf("%d\n", vowel_count);
	}
}