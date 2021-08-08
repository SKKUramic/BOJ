// 15904 UCPC는 무엇의 약자일까?
// https://www.acmicpc.net/problem/15904
#include <stdio.h>
#include <string.h>

int main(){
	int len = 0, UCPC = 0;
	char sentence[1001];
	scanf("%[^\n]s", sentence);
	len = strlen(sentence);
	for (int i = 0; i < len; i++){
		if (UCPC == 4){break;}
		if (sentence[i] == 'U'){
			if (UCPC == 0){
				UCPC++;
			}
		}
		else if (sentence[i] == 'C') {
			if (UCPC == 1 || UCPC == 3){
				UCPC++;
			}
		}
		else if (sentence[i] == 'P'){
			if (UCPC == 2){
				UCPC++;
			}
		}
	}
	if (UCPC == 4){
		printf("I love UCPC");
	}
	else {
		printf("I hate UCPC");
	}
}