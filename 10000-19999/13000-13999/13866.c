// 13866 팀 나누기
// https://www.acmicpc.net/problem/13866
#include <stdio.h>

int main(){
	int a, b, c, d;
	int team1, team2;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	team1 = (a + d);
	team2 = (b + c);
	printf("%d", team1 > team2 ? team1 - team2 : team2 - team1);
}