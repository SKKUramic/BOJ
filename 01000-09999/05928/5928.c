// 5928 Contest Timing
// https://www.acmicpc.net/problem/5928
#include <stdio.h>

int main(){
	int day, hour, minute, answer;
	scanf("%d %d %d", &day, &hour, &minute);
	answer = day * 1440 + hour * 60 + minute - 16511;
	if (answer < 0){printf("-1");}
	else {printf("%d", answer);}
}