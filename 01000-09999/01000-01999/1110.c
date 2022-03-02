// 1110 더하기 사이클
// https://www.acmicpc.net/problem/1110
#include <stdio.h>
//#include <stdlib.h>

int main(int argc, char* argv[]) {
	int org, first, second, answer = -1, count = 0;
	scanf("%d", &org);
	first = org / 10;
	second = org % 10;
	while (org != answer){
		answer = second * 10 + (first + second) % 10;
		//printf("first:%d second:%d answer:%d\n", first, second, answer);
		first = second;
		second = answer % 10;
		count++;
		//sleep(1);
	}
	printf("%d", count);
}