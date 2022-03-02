// 1850 최대공약수
// https://www.acmicpc.net/problem/1850
// https://www.acmicpc.net/board/view/32699 <- 증명, 역시 머리가 좋아야 코딩을 한다
#include <stdio.h>
typedef unsigned long long ull;

ull Euclidean(ull a, ull b){
	return a % b ? Euclidean(b, a % b) : b;
}

int main(){
	ull A, B, answer;
	scanf("%llu %llu", &A, &B);
	answer = Euclidean(A, B);
	for (ull i = 0; i < answer; i++){ // 두 수의 자릿수의 최대공약수만큼 1을 출력
		printf("1");
	}
}