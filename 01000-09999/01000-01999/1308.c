// 1308 D-Day
// https://www.acmicpc.net/problem/1308
// 날짜만 잘 판별하면 됩니다.
#include <stdio.h>

int Is_leap_year(int year){
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0){return 1;}
	else {return 0;}
}

int Day_sum(int year, int month){
	int day = 0;
	for (int i = 1; i < month; i++){
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
			day += 31;
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11){
			day += 30;
		}
		else {
			if (Is_leap_year(year) == 1){
				day += 29;
			}
			else {
				day += 28;
			}
		}
	}
	return day;
}

int main(){
	int year, month, day;
	int D_year, D_month, D_day, DAY;
	int sum = 0, D_sum = 0;
	scanf("%d %d %d", &year, &month, &day);
	scanf("%d %d %d", &D_year, &D_month, &D_day);
	if (D_year > year + 1000 || D_year >= year + 1000 && D_month >= month && D_day >= day){
		printf("gg");
		return 0;
	}
	sum = Day_sum(year, month);
	sum += day;
	D_sum = Day_sum(D_year, D_month);
	D_sum += D_day;
	for (int i = year; i < D_year; i++){
		if (Is_leap_year(i) == 1){D_sum += 366;}
		else {D_sum += 365;}
	}
	printf("D-%d", D_sum - sum);
}