// 11778 피보나치 수와 최대공약수
// https://www.acmicpc.net/problem/11778
#include <stdio.h>

long long REMAINDER = 1000000007;

long long Euclidian(long long a, long long b){
	return a % b ? Euclidian(b, a % b) : b;
}

long long ret_Fibonacci(long long N){
	long long fibonacci[2][2] = {{1, 1}, {1, 0}}, answer[2][2] = {{1, 0}, {0, 1}}, temp[2][2];
	while (N > 0){
		temp[0][0] = 0; temp[0][1] = 0; temp[1][0] = 0; temp[1][1] = 0;
		if (N % 2 == 1){
			for (int i = 0; i < 2; i++){
				for (int j = 0; j < 2; j++){
					for (int k = 0; k < 2; k++){
						temp[i][j] += answer[i][k] * fibonacci[k][j];
						temp[i][j] %= REMAINDER; 
					}
				}
			}
			for (int i = 0; i < 2; i++){
				for (int j = 0; j < 2; j++){
					answer[i][j] = temp[i][j];
				}
			}
		}
		temp[0][0] = 0; temp[0][1] = 0; temp[1][0] = 0; temp[1][1] = 0;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				for (int k = 0; k < 2; k++){
					temp[i][j] += fibonacci[i][k] * fibonacci[k][j];
					temp[i][j] %= REMAINDER; 
				}
			}
		}
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				fibonacci[i][j] = temp[i][j];
			}
		}
		N /= 2;
	}
	return answer[1][0] % REMAINDER;
}

int main(){
	long long N, M, Fn, Fm;
	scanf("%lld %lld", &N, &M);
	printf("%lld", ret_Fibonacci(Euclidian(N, M)));
}