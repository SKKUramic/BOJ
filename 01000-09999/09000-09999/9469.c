// 9469 폰 노이만
// https://www.acmicpc.net/problem/9469
#include <stdio.h>

int main() {
	int P, N;
	double D, A, B, F;
	scanf("%d", &P);
	for (int i = 0; i < P; i++){
		scanf("%d", &N);
		scanf("%lf %lf %lf %lf", &D, &A, &B, &F);
		printf("%d %lf\n", N, D * F / (A + B));
	}
}