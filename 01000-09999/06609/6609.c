// 6609 모기곱셈
#include <stdio.h>

int main(){
	int M, P, L, E, R, S, N; // M마리의 모기, P개의 번데기, L마리의 유충, E개의 알을 낳음, R번째 유충만 살아남음, S번째 번데기만 살아남음, N번쨰 주
	int egg = 0, temp;
	while (scanf("%d %d %d %d %d %d %d", &M, &P, &L, &E, &R, &S, &N) != EOF){
		for (int i = 0; i < N; i++){
			egg = M * E;
			M = P / S;
			P = L / R;
			L = egg;
		}
		printf("%d\n", M);
	}
}