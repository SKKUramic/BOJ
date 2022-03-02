// 2195 문자열 복사
// https://www.acmicpc.net/problem/2195
#include <stdio.h>
#include <string.h>

char S[1001];
char P[1001];

int main(){
	int Slen, Plen, current_idx = 0, copy_len, sequence, copy_count = 0;
	scanf("%s", S);
	scanf("%s", P);
	Slen = strlen(S);
	Plen = strlen(P);
	while (current_idx < Plen){
		copy_len = 0;
		sequence = 0;
		for (int idx = 0; idx < Slen; idx++){
			if (S[idx] == P[current_idx + sequence]){
				sequence++;
			}
			else {
				if (copy_len < sequence){
					copy_len = sequence;
				}
				sequence = 0;
			}
		}
		if (copy_len < sequence){
			copy_len = sequence;
		}
		current_idx += copy_len;
		copy_count++;
	}
	printf("%d", copy_count);
}