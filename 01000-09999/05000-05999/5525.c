// 5525 IOIOI
// https://www.acmicpc.net/problem/5525
#include <stdio.h>

int main(){
	int N, M, length = 0, count = 0;
	char S[1000001];
	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%s", S);
	N = 2 * N + 1;
	for (int i = 0; i < M; i++){
		if (length % 2 == 0 && S[i] == 'I' || length % 2 == 1 && S[i] == 'O'){
			length++;
		}
		else if (length % 2 == 1 && S[i] == 'I'){
			length = 1;
		}
		else if (length % 2 == 0 && S[i] == 'O'){
			length = 0;
		}
		if (length == N){
			count++;
			length -= 2;
		}
	}
	printf("%d", count);
}