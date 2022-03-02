// 10768 특별한 날
// https://www.acmicpc.net/problem/10768
#include <stdio.h>

int main(){
	int month, day;
	scanf("%d %d", &month, &day);
	if (month == 2 && day == 18){printf("Special");}
	else if (month < 2 || (month == 2 && day < 18)){printf("Before");}
	else if (month > 2 || (month == 2 && day > 18)){printf("After");}
}