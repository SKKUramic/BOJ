// 2224 명제 증명
// https://www.acmicpc.net/problem/2224
#include <stdio.h>

bool Logic[55][55];
int answer[3000][2];

void Floyd_Warshall(){
	for (int k = 0; k < 52; k++){
		for (int start = 0; start < 52; start++){
			for (int end = 0; end < 52; end++){
				if (Logic[start][k] == true && Logic[k][end] == true){
					Logic[start][end] = true;
				}
			}
		}
	}
	return;
}

int main(){
	int N, Pidx, Qidx, Tcount = 0;
	char P, Q;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf(" %c => %c", &P, &Q);
		if (P >= 'a'){Pidx = P - 'a' + 26;}
		else {Pidx = P - 'A';}
		if (Q >= 'a'){Qidx = Q - 'a' + 26;}
		else {Qidx = Q - 'A';}
		Logic[Pidx][Qidx] = true;
	}
	Floyd_Warshall();
	for (int i = 0; i < 52; i++){
		for (int j = 0; j < 52; j++){
			if (i != j && Logic[i][j] == true){
				answer[Tcount][0] = i;
				answer[Tcount][1] = j;
				Tcount++;
			}
		}
	}
	printf("%d\n", Tcount);
	for (int t = 0; t < Tcount; t++){
		if (answer[t][0] >= 26){P = 'a' + (answer[t][0] - 26);}
		else {P = 'A' + answer[t][0];}
		if (answer[t][1] >= 26){Q = 'a' + (answer[t][1] - 26);}
		else {Q = 'A' + answer[t][1];}
		printf("%c => %c\n", P, Q);
	}
}