// 19575 Polynomial
// https://www.acmicpc.net/problem/19575
#include <stdio.h>

long long int Polynomial[1000010] = {0, };

int main(){
	int n, idx;
	long long int x, p, answer = 0;
	scanf("%d %lld", &n, &x);
	for (int i = 0; i < n + 1; i++){
		scanf("%lld %d", &p, &idx);
		Polynomial[idx] = p;
	}
	idx = n;
	answer = Polynomial[idx];
	while (idx > 0){
		answer *= x;
		answer += Polynomial[--idx];
		answer %= 1000000007;
	}
	printf("%lld", answer);
}