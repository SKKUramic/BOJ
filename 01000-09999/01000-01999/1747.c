// 1747 소수&팰린드롬
// https://www.acmicpc.net/problem/1747
#include <stdio.h>

int isprime(int N){
	for (int i = 2; i * i <= N; i++){
		if (N % i == 0){return 0;}
	}
	return 1;
}

int ispalindrome(int N){
	int idx = 0;
	int arr[10];
	while (N > 0){
		arr[idx++] = N % 10;
		N /= 10;
	}
	for (int i = 0; i <= idx / 2; i++){
		if (arr[i] != arr[idx - i - 1]){return 0;}
	}
	return 1;
}

int main(){
	int X;
	scanf("%d", &X);
	if (X == 1){X++;}
	while (1){
		if (ispalindrome(X) && isprime(X)){break;}
		X++;
	}
	printf("%d", X);
}