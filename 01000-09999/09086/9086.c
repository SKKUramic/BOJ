// 9086 문자열
// https://www.acmicpc.net/problem/9086
#include <stdio.h>
#include <string.h>

int main(){
	int T, len;
	char S[1001];
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%s", S);
		len = strlen(S);
		printf("%c%c\n", S[0], S[len - 1]);
	}
}