// 2720 세탁소 사장 동혁
// https://www.acmicpc.net/problem/2720
#include <stdio.h>

int main(){
	int Cent, Q, D, N, P, TC;
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d", &Cent);
		Q = Cent / 25;
		Cent %= 25;
		D = Cent / 10;
		Cent %= 10;
		N = Cent / 5;
		Cent %= 5;
		P = Cent;
		printf("%d %d %d %d\n", Q, D, N, P);
	}
}