// 2668 줄어들지 않아
// https://www.acmicpc.net/problem/2688
// 11057 오르막 수 문제의 강화판...?
#include <stdio.h>

long long Ascending_number[65][10] = {0, };

int main(){
	int T, N;
	long long answer;
	scanf("%d", &T);
	while (T-- > 0){
		answer = 0;
		scanf("%d", &N);
		for (int x = 0; x < 10; x++){Ascending_number[1][x] = 1;}
		for (int k = 2; k <= N; k++){
			for (int x = 0; x < 10; x++){
				Ascending_number[k][x] = 0;
				for (int xx = x; xx < 10; xx++){
					Ascending_number[k][x] += Ascending_number[k - 1][xx];
				}
			}
		}
		for (int x = 0; x < 10; x++){answer += Ascending_number[N][x];}
		printf("%lld\n", answer);
	}
}