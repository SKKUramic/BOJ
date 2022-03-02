// 11655 ROT13
// https://www.acmicpc.net/problem/11655
#include <stdio.h>
#include <string.h>

int main(){
	int len;
	char s[101];
	scanf("%[^\n]s", s);
	len = strlen(s);
	for (int i = 0; i < len; i++){
		if (s[i] >= 'A' && s[i] <= 'Z'){
			printf("%c", 'A' + (s[i] - 'A' + 13) % 26);
		}
		else if (s[i] >= 'a' && s[i] <= 'z'){
			printf("%c", 'a' + (s[i] - 'a' + 13) % 26);
		}
		else {
			printf("%c", s[i]);
		}
	}
}