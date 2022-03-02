// 1159 농구 경기
// https://www.acmicpc.net/problem/1159
#include <stdio.h>

int alpha[26] = {0, };
char name[31];

int main(){
	int T, five = 0;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%s", name);
		alpha[name[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++){
		if (alpha[i] >= 5){
			printf("%c", i + 'a');
			five++;
		}
	}
	if (five == 0){
		printf("PREDAJA");
	}
}