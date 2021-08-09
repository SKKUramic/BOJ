// 13250 주사위 게임
// https://www.acmicpc.net/problem/13250
#include <stdio.h>

double divisor = 6.000000000000000;
double dice[1000001]; // n의 기댓값

int main(){
	int N;
	dice[1] = 1.000000000000000;
	scanf("%d", &N);
	for (int n = 2; n <= N; n++){
		if (n <= 6){
			double sum = 0.000000000000000;
			for (int nn = 1; nn <= n; nn++){
				sum += dice[nn];
			}
			dice[n] = 1.000000000000000 + sum / divisor; // 일단 못해도 한 번은 던져야 하지 않겠어?
		}
		else {
			dice[n] = 1.000000000000000 + (dice[n - 1] + dice[n - 2] + dice[n - 3] + dice[n - 4] + dice[n - 5] + dice[n - 6]) / divisor;
		}
	}
	printf("%.15lf", dice[N]);
}