// 9665 돌 게임
#include <stdio.h>

int main(){
	int rock, turn = 0;
	scanf("%d", &rock);
	turn += rock / 3;
	turn += rock % 3;
	if (turn % 2 == 0){
		printf("CY");
	}
	else {
		printf("SK");
	}
}