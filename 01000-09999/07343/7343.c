// 7343 달력 놀이
// https://www.acmicpc.net/problem/7343
#include <stdio.h>
#include <string.h>

int DP[110][13][35];
int NDyear, NDmonth, NDday, NMyear, NMmonth, NMday;
// 다음 날 혹은 다음 달이 원래는 지는 경우였다면, 이 날에서는 승리함

int leap_year(int year){
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){return 1;}
	else {return 0;}
}

int retDay(int year, int month){
	if ((month % 2 == 1 && month <= 7) || (month % 2 == 0 && month >= 8)){return 31;}
	else if (month == 2){
		if (leap_year(year) == 1){return 29;}
		else {return 28;}
	}
	else {return 30;}
}

void nextDay(int year, int month, int day){
	NDyear = year; NDmonth = month; NDday = day;
	if (day == retDay(year, month)){
		NDday = 1;
		if (month == 12){
			NDmonth = 1;
			NDyear++;
		}
		else {
			NDmonth++;
		}
	}
	else {
		NDday++;
	}
	return;
}

void nextMonth(int year, int month, int day){
	if (month == 12){
		if (day <= retDay(year + 1, 1)){
			NMyear = year + 1; NMmonth = 1; NMday = day;
		}
		else {
			NMyear = -1; NMmonth = -1; NMday = -1;
		}
	}
	else {
		if (day <= retDay(year, month + 1)){
			NMyear = year; NMmonth = month + 1; NMday = day;
		}
		else {
			NMyear = -1; NMmonth = -1; NMday = -1;
		}
	}
	return;
}

int getMin(){
	if (NMyear == -1){return DP[NDyear - 1900][NDmonth][NDday] + 1;}
	int retA = DP[NDyear - 1900][NDmonth][NDday];
	int retB = DP[NMyear - 1900][NMmonth][NMday];
	if (retA == -1){return retB + 1;}
	if (retB == -1){return retA + 1;}
	if (retA % 2 == 0 || retB % 2 == 0){return 1;}
	else {return 0;}
}

int main(){
	int TC, YYYY, MM, DD;
	int year, month, day;
	scanf("%d", &TC);
	memset(DP, -1, 110 * 13 * 35 * sizeof(int));
	DP[2001 - 1900][11][4] = 0;
	for (year = 2001; year >= 1900; year--){
		for (month = 12; month >= 1; month--){
			day = retDay(year, month);
			if (year == 2001 && month == 11){day = 3;}
			for (; day >= 1; day--){
				nextDay(year, month, day);
				nextMonth(year, month, day);
				DP[year - 1900][month][day] = getMin();
			}
		}
	}
	while (TC-- > 0){
		scanf("%d %d %d", &YYYY, &MM, &DD);
		if (DP[YYYY - 1900][MM][DD] % 2 == 1){
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}	
	}
}