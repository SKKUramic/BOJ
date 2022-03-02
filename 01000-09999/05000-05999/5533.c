// 5533 유니크
// https://www.acmicpc.net/problem/5533
#include <stdio.h>

int num[101] = {0, };
int score[201] = {0, };
int input[201][3] = {0, };

int main(){
	int N;
	scanf("%d", &N);
	for (int n = 1; n <= N; n++){
		for (int i = 0; i < 3; i++){
			scanf("%d", &input[n][i]);
		}
	}
	for (int i = 0; i < 3; i++){
		for (int k = 0; k <= 100; k++){num[k] = 0;}
		for (int n = 1; n <= N; n++){
			num[input[n][i]]++;
		}
		for (int n = 1; n <= N; n++){
			if (num[input[n][i]] == 1){
				score[n] += input[n][i];
			}
		}
	}
	for (int n = 1; n <= N; n++){
		printf("%d\n", score[n]);
	}
}