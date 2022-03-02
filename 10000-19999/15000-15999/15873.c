// 15873 공백 없는 A+B
// https://www.acmicpc.net/problem/15873
#include <stdio.h>
#include <string.h>

int main(){
	char num[5];
	scanf("%s", num);
	if (strlen(num) == 2){
		printf("%d", num[0] - '0' + num[1] - '0');
	}
	else if (strlen(num) == 3){
		if (num[1] == '0'){
			printf("%d", 10 + num[2] - '0');
		}
		else {
			printf("%d", num[0] - '0' + 10);
		}
	}
	else {
		printf("20");
	}
}