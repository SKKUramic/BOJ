// 8989 시계
// https://www.acmicpc.net/problem/8989
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct Clock{
	int hour;
	int minute;
	int degree;
}Clock;

Clock clock[5];

int retDegree(int hour, int minute){
	int degree = minute * 60 - (hour * 300 + minute * 5); // 분침은 1분에 6도, 시침은 1분에 0.5도, 1시간에 30도씩 움직임
	if (degree < 0){degree = -degree;}
	if (degree > 1800){degree = 3600 - degree;}
	return degree;
}

bool cmp(Clock a, Clock b){
	if (a.degree == b.degree){
		if (a.hour == b.hour){return a.minute < b.minute;}
		return a.hour < b.hour;
	}
	return a.degree < b.degree;
}

int main(){
	int TC, hh, mm;
	scanf("%d", &TC);
	while (TC-- > 0){
		for (int i = 0; i < 5; i++){
			scanf("%d:%d", &hh, &mm);
			clock[i].hour = hh;
			clock[i].minute = mm;
			clock[i].degree = retDegree(hh % 12, mm);
		}
		sort(clock, clock + 5, cmp);
		//for (int i = 0; i < 5; i++){printf("%02d:%02d->%d ", clock[i].hour, clock[i].minute, clock[i].degree);}
		printf("%02d:%02d\n", clock[2].hour, clock[2].minute);
	}
}