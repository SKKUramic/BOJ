// 1100 하얀 말
// https://www.acmicpc.net/problem/1100
#include <stdio.h>

char chess[9][9];

int main(){
	int answer = 0;
	for (int i = 0; i < 8; i++){
		scanf("%s", chess[i]);
	}
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (chess[i][j] == 'F' && (i + j) % 2 == 0){
				answer++;
			}
		}
	}
	printf("%d", answer);
}