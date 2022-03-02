// 1094 막대기
// https://www.acmicpc.net/problem/1094
#include <stdio.h>

int main(){
	int want, count = 0, stick = 0;
	scanf("%d", &want);
	for (int i = 6; i >= 0; i--){
		if (stick + (1 << i) <= want){
			count++;
			stick += 1 << i;
		}
	}
	printf("%d", count);
}