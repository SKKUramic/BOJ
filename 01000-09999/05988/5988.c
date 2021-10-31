// 5988 홀수일까 짝수일까
// https://www.acmicpc.net/problem/5988
#include <stdio.h>
#include <string.h>

int main(){
	int T;
	char number[100];
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%s", number);
		if ((number[strlen(number) - 1] - '0') % 2 == 0){
			printf("even\n");
		}
		else {
			printf("odd\n");
		}
	}
}