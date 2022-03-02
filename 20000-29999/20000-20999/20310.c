// 20310 타노스
// https://www.acmicpc.net/problem/20310
#include <stdio.h>
#include <string.h>

char str[501];

int main(){
	int len, zero_idx, one_idx, zero_count = 0, one_count = 0, removed;
	scanf("%s", str);
	len = strlen(str);
	zero_idx = len - 1;
	one_idx = 0;
	for (int i = 0; i < len; i++){
		if (str[i] == '0'){
			zero_count++;
		}
		else if (str[i] == '1'){
			one_count++;
		}
	}
	removed = 0;
	while (removed != zero_count / 2){
		if (str[zero_idx] == '0'){
			str[zero_idx] = 'X';
			removed++;
		}
		zero_idx--;
	}
	removed = 0;
	while (removed != one_count / 2){
		if (str[one_idx] == '1'){
			str[one_idx] = 'X';
			removed++;
		}
		one_idx++;
	}
	for (int i = 0; i < len; i++){
		if (str[i] != 'X'){
			printf("%c", str[i]);
		}
	}
}