// 16900 이름 정하기
// https://www.acmicpc.net/problem/16900
#include <stdio.h>
#include <string.h>

char S[500010];
long long int pi[500010] = {0, };

int main(){
	long long int K;
	scanf("%s %lld", S, &K);
	long long int start = 1, idx = 0;
	long long int max = 0;
	long long int len = strlen(S);
	while (start + idx < len){
		if (S[start + idx] == S[idx]){
			idx++;
			pi[start + idx - 1] = idx;
		}
		else {
			if (idx == 0){
				start++;
			}
			else {
				start += (idx - pi[idx - 1]);
				idx = pi[idx - 1];
			}
		}
	}
	for (int i = 0; i < len; i++){
		if (max < pi[i]){max = pi[i];}
	}
	//printf("%lld %lld %lld\n", len, max, K);
	printf("%lld", len * K - pi[len - 1] * (K - 1));
}