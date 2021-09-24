// 20004 베스킨라빈스 31
// https://www.acmicpc.net/problem/20004
#include <stdio.h>

int first_win[32] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	first_win[30] = 1; first_win[31] = 1; // 30과 31은 첫 턴에 죽일 수 있다
	for (int i = 1; i < 30; i++){
		if (31 % (i + 1) != 1){first_win[i] = 1;}
	}
	for (int i = 1; i <= N; i++){
		if (first_win[i] == 0){
			printf("%d\n", i);
		}
	}
}