// 1652 누울 자리를 찾아라
// https://www.acmicpc.net/problem/1652
#include <stdio.h>

char FLOOR[101][101];

int main(){
	int N, seat, count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%s", FLOOR[i]);
	}
	for (int i = 0; i < N; i++){
		seat = 0;
		for (int j = 0; j < N; j++){
			if (FLOOR[i][j] == '.'){seat++;}
			else {
				if (seat >= 2){count++;}
				seat = 0;
			}
		}
		if (seat >= 2){count++;}
	}
	printf("%d ", count);
	count = 0;
	for (int i = 0; i < N; i++){
		seat = 0;
		for (int j = 0; j < N; j++){
			if (FLOOR[j][i] == '.'){seat++;}
			else {
				if (seat >= 2){count++;}
				seat = 0;
			}
		}
		if (seat >= 2){count++;}
	}
	printf("%d", count);
}