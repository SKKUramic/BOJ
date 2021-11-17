// 23207 1번부터 문제의 상태가…?
// https://www.acmicpc.net/problem/23027
#include <stdio.h>
#include <string.h>

int main(){
	int alphabet[26] = {0, };
	char message[1001];
	scanf("%s", message);
	for (int i = 0; i < strlen(message); i++){
		alphabet[message[i] - 'A']++;
	}
	if (alphabet[0] > 0){
		for (int i = 0; i < strlen(message); i++){
			if ('A' <= message[i] && message[i] <= 'F' && message[i] != 'E'){
				message[i] = 'A';
			}
		}
	}
	else if (alphabet[1] > 0){
		for (int i = 0; i < strlen(message); i++){
			if ('B' <= message[i] && message[i] <= 'F' && message[i] != 'E'){
				message[i] = 'B';
			}
		}
	}
	else if (alphabet[2] > 0){
		for (int i = 0; i < strlen(message); i++){
			if ('C' <= message[i] && message[i] <= 'F' && message[i] != 'E'){
				message[i] = 'C';
			}
		}
	}
	else {
		for (int i = 0; i < strlen(message); i++){
			message[i] = 'A';
		}
	}
	printf("%s", message);
}