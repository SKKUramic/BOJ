// 21612 Boiling Water
// https://www.acmicpc.net/problem/21612
#include <stdio.h>

int main(){
	int B, kPa;
	scanf("%d", &B);
	kPa = 5 * B - 400;
	printf("%d\n", kPa);
	if (kPa > 100){
		printf("-1");
	}
	else if (kPa < 100){
		printf("1");
	}
	else {
		printf("0");
	}
}