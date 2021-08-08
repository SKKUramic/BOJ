// 5426 비밀 편지
// https://www.acmicpc.net/problem/5426
#include <stdio.h>
#include <string.h>
#include <math.h>

char letter[10001];

int main(){
	int T, len, SQRT;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%s", letter);
		len = strlen(letter);
		SQRT = (int)sqrt(len);
		for (int i = SQRT - 1; i >= 0; i--){
			for (int j = i; j < len; j += SQRT){
				printf("%c", letter[j]);
			}
		}
		printf("\n");
	}
}