// 10798 세로읽기
// https://www.acmicpc.net/problem/10798
#include <stdio.h>
#include <string.h>

char arr[5][15];

int main(){
	int max_len = -1;
	for (int i = 0; i < 5; i++){
		scanf("%s", arr[i]);
		if (max_len < strlen(arr[i])){
			max_len = strlen(arr[i]);
		}
		for (int k = strlen(arr[i]); k < 15; k++){
			arr[i][k] = '#';
		}
	}
	for (int k = 0; k < 15; k++){
		for (int i = 0; i < 5; i++){
			if (arr[i][k] != '#'){printf("%c", arr[i][k]);}
		}
	}
}