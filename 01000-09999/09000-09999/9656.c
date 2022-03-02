// 9656 돌 게임 2
// 9655 돌 게임 의 코드와 동일하나, 출력만 반대이다.
#include <stdio.h>

int main(){
	int rock, turn = 0;
	scanf("%d", &rock);
	turn += rock / 3;
	turn += rock % 3;
	if (turn % 2 == 0){
		printf("SK");
	}
	else {
		printf("CY");
	}
}