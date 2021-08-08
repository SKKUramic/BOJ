// 1032 명령 프롬프트
// https://www.acmicpc.net/problem/1032
#include <stdio.h>
#include <string.h>

int main(){
	char answer[100];
	char word[100];
	int test, len;
	scanf("%d", &test);
	scanf("%s", answer);
	len = strlen(answer);
	for (int i = 1; i < test; i++){
		scanf("%s", word);
		for (int j = 0; j < len; j++){
			if (answer[j] != word[j]){
				answer[j] = '?';
			}
		}
	}
	printf("%s", answer);
}