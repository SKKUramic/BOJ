// 2193 이친수
// https://www.acmicpc.net/problem/2193
// 그래도 '2201 이친수 찾기'보다 매우 쉽다
#include <stdio.h>

long long fibonacci[91] = {0, };

int main(){
	int idx = 0;
	long long n;
	fibonacci[0] = 0;	fibonacci[1] = 1; // 0번째 피보나치 수를 0, 1번째 피보나치 수를 1로 함
	for (int i = 2; i <= 90; i++){fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];} // 89번째 피보나치 수가 K의 최댓값보다 큼
	scanf("%lld", &n);
	printf("%lld", fibonacci[n]);
}