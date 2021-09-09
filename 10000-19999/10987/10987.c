// 10987 모음의 개수
// https://www.acmicpc.net/problem/10987
#include <stdio.h>
#include <string.h>

int vowel(char c){
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){return 1;}
	return 0;
}

int main(){
	int count = 0, len;
	char S[101];
	scanf("%s", S);
	len = strlen(S);
	for (int i = 0; i < len; i++){
		count += vowel(S[i]);
	}
	printf("%d", count);
}