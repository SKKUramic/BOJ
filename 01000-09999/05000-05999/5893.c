// 5893 17배 
// https://www.acmicpc.net/problem/5893
// 파이썬으로 하면 쉽다는데...
#include <stdio.h>
#include <string.h>

char two_array[1010];
char two_array_copy[1010];
char answer[1010];

int main(){
	int len, count_up = 0;
	int is_one, is_one_copy, is_one_count_up;
	scanf("%s", two_array);
	len = strlen(two_array);
	for (int i = len; i < len + 4; i++){
		two_array[i] = '0';
		two_array_copy[i - len] = '0';
	}
	for (int i = 0; i < len; i++){
		two_array_copy[i + 4] = two_array[i];
	}
	for (int i = len + 3; i >= 0; i--){
		is_one = two_array[i] == '1' ? 1 : 0;
		is_one_copy = two_array[i - 4] == '1' ? 1 : 0;
		if ((is_one + is_one_copy + count_up) % 2 == 0){
			answer[i] = '0';
		}
		else {
			answer[i] = '1';
		}
		if (is_one + is_one_copy + count_up >= 2){
			count_up = 1;
		}
		else {
			count_up = 0;
		}
	}
	if (count_up == 1){
		printf("1");
	}
	printf("%s", answer);
}