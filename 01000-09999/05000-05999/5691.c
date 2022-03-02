// 5691 평균 중앙값 문제
// https://www.acmicpc.net/problem/5691
// 문제의 조건에 따라 A가 중앙값임
#include <stdio.h>

int main(){
	unsigned int a, b, c;
	scanf("%d %d", &a, &b);
	while (a != 0 || b != 0){
		c = 2 * a - b;
		printf("%d\n", c);
		scanf("%d %d", &a, &b);
	}
}