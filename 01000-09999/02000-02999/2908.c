// 2908 상수
#include <stdio.h>
#include <string.h>

int main(){
	int num1, num2, rev1 = 0, rev2 = 0;
	scanf("%d %d", &num1, &num2);
	rev1 = (num1 % 10) * 100 + ((num1 / 10) % 10) * 10 + (num1 / 100);
	rev2 = (num2 % 10) * 100 + ((num2 / 10) % 10) * 10 + (num2 / 100);
	printf("%d", rev1 > rev2 ? rev1 : rev2);
}