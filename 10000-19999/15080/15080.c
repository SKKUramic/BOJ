// 15080 Every Second Counts
// https://www.acmicpc.net/problem/15080
#include <stdio.h>

int main(){
	int hour1, minute1, second1, hour2, minute2, second2;
	int SECOND1, SECOND2;
	scanf("%d : %d : %d", &hour1, &minute1, &second1);
	scanf("%d : %d : %d", &hour2, &minute2, &second2);
	SECOND1 = 3600 * hour1 + 60 * minute1 + second1;
	SECOND2 = 3600 * hour2 + 60 * minute2 + second2;
	if (SECOND1 > SECOND2){
		SECOND2 += 86400;
	}
	/*
	if (hour1 > hour2 || (hour1 == hour2 && minute1 > minute2) || (hour1 == hour2 && minute1 == minute2 && second1 > second2)){
		SECOND2 += 86400;
	}*/
	printf("%d", SECOND2 - SECOND1);
}