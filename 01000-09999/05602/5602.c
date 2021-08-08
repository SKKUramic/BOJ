// 5602 問題1
// JOI 2006 문제1입니다.
// https://www.acmicpc.net/problem/5602
#include <stdio.h>

int score_priority[1001][101];
int score_idx[1001] = {0, };
int score[101] = {0, };

int main(){
	int N, M, count = 0;
	int OX, high_score = -1;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			scanf("%d", &OX);
			score[j] += OX;
		}
	}
	for (int i = 1; i <= M; i++){
		if (high_score < score[i]) {high_score = score[i];}
		score_priority[score[i]][score_idx[score[i]]++] = i;
	}
	for (int i = high_score; count < M; i--){
		for (int j = 0; j < score_idx[i]; j++){
			printf("%d ", score_priority[i][j]);
			count++;
		}
	}
}