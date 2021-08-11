// 2711 오타맨 고창영
// https://www.acmicpc.net/problem/2711
#include <stdio.h>
#include <string.h>

int main(){
	int T, idx;
	char word[100];
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d %s", &idx, word);
		for (int i = 0; i < strlen(word); i++){
			if (i == idx - 1){continue;}
			printf("%c", word[i]);
		}
		printf("\n");
	}
}