// 8558 Silnia
// https://www.acmicpc.net/problem/8558
// n!의 일의 자리를 출력하는 문제
#include <stdio.h>

int main(){
	int n, ans = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		ans = (ans * i) % 10;
	}
	printf("%d", ans);
}