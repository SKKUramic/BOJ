// 1225 이상한 곱셈
// https://www.acmicpc.net/problem/1225
#include <stdio.h>
#include <string.h>

int main(){
	int A_len, B_len;
	long long int answer = 0;
	char A[10001], B[10001];
	scanf("%s %s", A, B);
	A_len = strlen(A);
	B_len = strlen(B);
	for (int a = 0; a < A_len; a++){
		for (int b = 0; b < B_len; b++){
			answer += (A[a] - '0') * (B[b] - '0');
		}
	}
	printf("%lld", answer);
}