// 2902 KMP는 왜 KMP일까?
// https://www.acmicpc.net/problem/2902
#include <stdio.h>
#include <string.h>

int main(){
	int len;
	char name[101];
	scanf("%s", name);
	len = strlen(name);
	for (int i = 0; i < len; i++){
		if (i == 0 || name[i - 1] == '-'){
			printf("%c", name[i]);
		}
	}
}