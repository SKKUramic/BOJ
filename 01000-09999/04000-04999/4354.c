// 4354 문자열 제곱
// https://www.acmicpc.net/problem/4354
#include <stdio.h>
#include <string.h>

#define ERROR -999999

char S[1000010];
int pi[1000010] = {0, };

int main(){
	int K, s_idx, idx, len, loop_idx, count;
	scanf("%s", S);
	while (strlen(S) != 1 || S[0] != '.'){
		s_idx = 1, idx = 0;
		len = strlen(S);
		while (s_idx + idx < len){
			if (S[s_idx + idx] == S[idx]){
				idx++;
				pi[s_idx + idx - 1] = idx;
			}
			else {
				if (idx == 0){
					s_idx++;
				}
				else {
					s_idx += (idx - pi[idx - 1]);
					idx = pi[idx - 1];
				}
			}
		}
		loop_idx = len - pi[len - 1];
		idx = 0;	count = 0;
		for (int i = 0; i < len; i++){
			if (S[i] != S[idx]){
				count = ERROR;
				break;
			}
			else {
				idx = (idx + 1) % loop_idx;
				if (idx == 0){count++;}
			}
		}
		if (count == ERROR || idx != 0){
			printf("1\n");
		}
		else {
			printf("%d\n", count);	
		}
		scanf("%s", S);
	}
}