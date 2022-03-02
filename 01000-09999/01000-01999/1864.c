// 1864 문어 숫자
// https://www.acmicpc.net/problem/1864
#include <stdio.h>
#include <string.h>

char arr[10];

int octopus(char c){
	if (c == '-'){return 0;}
	else if (c == '\\') {return 1;}
	else if (c == '(') {return 2;}
	else if (c == '@') {return 3;}
	else if (c == '?') {return 4;}
	else if (c == '>') {return 5;}
	else if (c == '&') {return 6;}
	else if (c == '%') {return 7;}
	else if (c == '/') {return -1;}
	else {return 0;} // ERROR
}

int main(){
	int len, minus, num;
	scanf("%s", arr);
	while (strlen(arr) != 1 || arr[0] != '#'){
		num = 0;
		len = strlen(arr);
		for (int i = 0; i < len; i++){
			num *= 8;
			num += octopus(arr[i]);
		}
		printf("%d\n", num);
		scanf("%s", arr);
	}
}