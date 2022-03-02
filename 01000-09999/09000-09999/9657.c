// 9657 돌 게임 3
// https://www.acmicpc.net/problem/9657
#include <stdio.h>

int stone[1001] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	stone[1] = 1; stone[2] = 2; stone[3] = 1; stone[4] = 1;
	for (int i = 5; i <= N; i++){
		if ((stone[i - 1] + stone[1]) % 2 == 1){stone[i] = 1;}
		else if ((stone[i - 3] + stone[3]) % 2 == 1){stone[i] = 1;}
		else if ((stone[i - 4] + stone[4]) % 2 == 1){stone[i] = 1;}
		else {stone[i] = 2;}
	}
	if (stone[N] == 1){printf("SK");}
	else {printf("CY");}
}