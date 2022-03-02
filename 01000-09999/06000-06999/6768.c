// 6768 Don’t pass me the ball!
// https://www.acmicpc.net/problem/6768
#include <stdio.h>

int Combination(int n){
	return (n - 1) * (n - 2) * (n - 3) / 6;
}

int main(){
	int J;
	scanf("%d", &J);
	printf("%d", Combination(J));
}