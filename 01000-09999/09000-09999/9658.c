// 9658 돌 게임 4
// https://www.acmicpc.net/problem/9658
#include <stdio.h>

int stone[1001] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	stone[1] = 1; stone[2] = 0; stone[3] = 1; stone[4] = 0;// 초깃값, 1이면 상근 패배 0이면 창영 패배 -> 1이면 창영 승리 0이면 상근 승리
	for (int i = 5; i <= N; i++){
		if (stone[i - 1] == 0 && stone[i - 3] == 0 && stone[i - 4] == 0){ // 어떤 방법으로도 상근의 패배를 막을 수 없을 때
			stone[i] = 1;
		}
		else {
			stone[i] = 0; // 어떤 방법으로 상근의 패배를 막을 수 있는 경우
		}
	}
	if (stone[N] == 1){printf("CY");}
	else {printf("SK");}
}