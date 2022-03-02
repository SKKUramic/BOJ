// 5575 타임 카드
// https://www.acmicpc.net/problem/5575
#include <stdio.h>

int main(){
	int start, start_hour, start_minute, start_second;
	int end, end_hour, end_minute, end_second;
	for (int i = 0; i < 3; i++){
		scanf("%d %d %d %d %d %d", &start_hour, &start_minute, &start_second, &end_hour, &end_minute, &end_second);
		start = start_hour * 3600 + start_minute * 60 + start_second;
		end = end_hour * 3600 + end_minute * 60 + end_second;
		printf("%d %d %d\n", (end - start) / 3600, ((end - start) / 60) % 60, (end - start) % 60);
	}
}