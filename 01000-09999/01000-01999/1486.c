// 1486 등산
// https://www.acmicpc.net/problem/1486
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 99999999

int Time[26][26] = {0, };
int Mountain[26][26] = {0, };
int Hiking[700][700] = {0, };
int dy[4] = {-1, 0, 0, 1}, dx[4] = {0, 1, -1, 0};
char Mountain_height[26][26];
int N, M, T, D;

void Floyd_Warshall(int n){
	for (int k = 0; k < n; k++){
		for (int start = 0; start < n; start++){
			for (int end = 0; end < n; end++){
				if (Hiking[start][end] > Hiking[start][k] + Hiking[k][end]){ // 실제로 이동가능한 좌표일 때
					Hiking[start][end] = Hiking[start][k] + Hiking[k][end];
				}
			}
		}
	}
	return;
}

int main(){
	int Sidx, Eidx, Yidx, Xidx, NM, y, x, diff;
	char height[30], answer;
	scanf("%d %d %d %d", &N, &M, &T, &D);
	for (int n = 0; n < N; n++){
		scanf(" %s", Mountain_height[n]);
		for (int m = 0; m < M; m++){
			if (Mountain_height[n][m] >= 'a'){
				Mountain[n][m] = (Mountain_height[n][m] - 'a') + 26;
			}
			else {Mountain[n][m] = Mountain_height[n][m] - 'A';}
		}
	}
	NM = N * M;
	answer = 'A';
	for (int i = 0; i < NM; i++){
		for (int j = 0; j < NM; j++){
			if (i != j){Hiking[i][j] = INF;}
		}
	}
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			Sidx = n * M + m;
			for (int i = 0; i < 4; i++){
				y = n + dy[i], x = m + dx[i];
				if (y < 0 || y >= N || x < 0 || x >= M){continue;}
				Eidx = y * M + x;
				diff = Mountain[n][m] - Mountain[y][x];
				if (abs(diff) > T){continue;}
				if (diff < 0){Hiking[Sidx][Eidx] = diff * diff;} // 낮은 곳에서 높은 곳으로 이동하는 것
				else {Hiking[Sidx][Eidx] = 1;} // 아니면 1초 걸림
			}
		}
	}
	Floyd_Warshall(NM);
	for (int idx = 0; idx < NM; idx++){
		if (D >= Hiking[0][idx] + Hiking[idx][0] && answer < Mountain_height[idx / M][idx % M]){
			answer = Mountain_height[idx / M][idx % M];
		}
	}
	if (answer >= 'a'){
		printf("%d", answer - 'a' + 26);
	}
	else {
		printf("%d", answer - 'A');
	}
}

/*
0	1 	2	3
4	5	6	7
8	9	10	11
12	13	14	15
16	17	18	19
*/