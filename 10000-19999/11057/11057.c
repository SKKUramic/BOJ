// 11057 오르막 수
// https://www.acmicpc.net/problem/11057
#include <stdio.h>

int Ascending_number[1001][10] = {0, };

int main(){
	int N, answer = 0;
	scanf("%d", &N);
	for (int x = 0; x < 10; x++){Ascending_number[1][x] = 1;}
	for (int k = 2; k <= N; k++){
		for (int x = 0; x < 10; x++){
			for (int xx = x; xx < 10; xx++){
				Ascending_number[k][x] += Ascending_number[k - 1][xx];
			}
			Ascending_number[k][x] %= 10007;
		}
	}
	for (int x = 0; x < 10; x++){answer += Ascending_number[N][x];}
	printf("%d", answer % 10007);
}