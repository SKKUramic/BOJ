// 5532 방학 숙제
// https://www.acmicpc.net/problem/5532
#include <stdio.h>

int main(){
	int L, A, B, C, D, language, math;
	scanf("%d %d %d %d %d", &L, &A, &B, &C, &D);
	language = A / C + (A % C == 0 ? 0 : 1);
	math = B / D + (B % D == 0 ? 0 : 1);
	if (language < math){
		printf("%d", L - math);
	}
	else {
		printf("%d", L - language);
	}
}