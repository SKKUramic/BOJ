// 2799 블라인드
// https://www.acmicpc.net/problem/2799
#include <stdio.h>

char window[510][510];
int curtain[5] = {0, };

int main(){
	int N, M, nidx, midx, blind;
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N * 5 + 1; n++){
		scanf("%s", window[n]);
	}
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			blind = 0;
			nidx = 5 * n + 1; midx = 5 * m + 1;
			if (window[nidx][midx] == '*'){blind++;}
			if (window[nidx + 1][midx] == '*'){blind++;}
			if (window[nidx + 2][midx] == '*'){blind++;}
			if (window[nidx + 3][midx] == '*'){blind++;}
			curtain[blind]++;
		}
	}
	for (int i = 0; i < 5; i++){
		printf("%d ", curtain[i]);
	}
}