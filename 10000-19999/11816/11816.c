// 11816 8진수, 10진수, 16진수
// https://www.acmicpc.net/problem/11816
#include <stdio.h>
#include <string.h>

char number[100];

int make_10(int idx, int time){
	int ret = 0;
	for (int i = idx; i < strlen(number); i++){
		if ('0' <= number[i] && number[i] <= '9'){
			ret = ret * time + number[i] - '0';
		}
		else {
			ret = ret * time + (number[i] - 'a' + 10);
		}
	}
	return ret;
}

int main(){
	int num;
	scanf("%s", number);
	if (number[0] == '0'){
		if (strlen(number) > 1 && number[1] == 'x'){
			printf("%d", make_10(2, 16));
		}
		else {
			printf("%d", make_10(1, 8));
		}
	}
	else {
		printf("%d", make_10(0, 10));
	}
}