// 2675 문자열 반복
#include <stdio.h>
#include <string.h>

int main(){
	char word[1000][20];
	int test, again, len;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d %s", &again, word[i]);
		len = strlen(word[i]);
		for (int j = 0; j < len; j++){
			for (int k = 0; k < again; k++){
				printf("%c", word[i][j]);
			}
		}
		printf("\n");
	}
}