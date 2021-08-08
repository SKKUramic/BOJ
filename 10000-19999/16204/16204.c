// 16204 카드 뽑기
// https://www.acmicpc.net/problem/16204
#include <stdio.h>

int main(){
	int N, M, K; //N = 총 카드 개수, M = O가 적힌 카드 개수, K = O를 적을 카드 개수
	int O_match, X_match;
	scanf("%d %d %d", &N, &M, &K);
	O_match = M < K ? M : K;
	X_match = (N - M) < (N - K) ? (N - M) : (N - K);
	printf("%d", O_match + X_match);
}