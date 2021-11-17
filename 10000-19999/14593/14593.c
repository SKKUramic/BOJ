// 14593 2017 아주대학교 프로그래밍 경시대회 (Large)
// https://www.acmicpc.net/problem/14593
#include <stdio.h>

int main(){
	int winner = 1, Ws, Wc, Wl;
	int S, C, L, TC;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++){
		scanf("%d %d %d", &S, &C, &L);
		if (i == 1){Ws = S; Wc = C; Wl = L;}
		else {
			if (Ws < S){
				winner = i;
				Ws = S; Wc = C; Wl = L;
			}
			else if (Ws == S){
				if (Wc > C){
					winner = i;
					Ws = S; Wc = C; Wl = L;
				}
				else if (Wc == C){
					if (Wl > L){
						winner = i;
						Ws = S; Wc = C; Wl = L;
					}
				}
			}
		}
	}
	printf("%d", winner);
}