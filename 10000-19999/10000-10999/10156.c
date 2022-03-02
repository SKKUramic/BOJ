// 10156 과자
// https://www.acmicpc.net/problem/10156
#include <stdio.h>

int main(){
	int snack_price, snack_count, money;
	scanf("%d %d %d", &snack_price, &snack_count, &money);
	if (snack_price * snack_count <= money){printf("0");}
	else {printf("%d", snack_price * snack_count - money);}
}