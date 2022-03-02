// 1402 아무래도이문제는A번난이도인것같다
// https://www.acmicpc.net/problem/1402
#include <stdio.h>

int main(){
	int A, B, TC;
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d %d", &A, &B);
		printf("yes\n");
	}
	// A = A * -1 * -1 * 1 * ... 이라고 표현이 가능해서 A에서 반드시 A''로 변환이 가능하다
}