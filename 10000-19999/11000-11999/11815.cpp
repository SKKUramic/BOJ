// 11815 짝수? 홀수?
// https://www.acmicpc.net/problem/11815
#include <stdio.h>
#include <cmath>

int main(){
	int N;
	long long num, sss;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%lld", &num);
		sss = (long long)sqrt((double)num);
		if (sss * sss == num){
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
}