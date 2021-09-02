// 3062 수 뒤집기
// https://www.acmicpc.net/problem/3062
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int TC, num, reverse_num, temp, X, len;
	int str[10];
	char flag;
	scanf("%d", &TC);
	while (TC-- > 0){
		reverse_num = 0;
		len = 0;
		flag = 'O';
		scanf("%d", &num);
		temp = num;
		while (temp > 0){
			reverse_num = reverse_num * 10 + temp % 10;
			temp /= 10;
		}
		X = num + reverse_num;
		while (X > 0){
			str[len++] = X % 10;
			X /= 10;
		}
		for (int i = 0; i < (len / 2); i++){
			if (str[i] != str[len - 1 - i]){
				flag = 'X';
			}
		}
		if (flag == 'O'){printf("YES\n");}
		else {printf("NO\n");}
	}
}