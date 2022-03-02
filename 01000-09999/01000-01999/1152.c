// 1152 단어의 개수
#include <stdio.h>
#include <string.h>

int main(){
	char word[1000000];
	int count = 0, clock = 0, len;
	int start, end;
	scanf("%[^\n]s", word);
	len = strlen(word);
	for (int i = 0; i < len; i++){
		if (word[i] == 32 && i != 0 && i != len - 1){
			count++;
		}
	}
	if (!(len == 1 && word[0] == 32)){
		count++;
	}
	printf("%d", count);
}