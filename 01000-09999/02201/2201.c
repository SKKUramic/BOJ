// 2201 이친수 찾기
// https://www.acmicpc.net/problem/2201
// 아니 이게 왜 피보나치???
#include <stdio.h>

long long fibonacci[90] = {0, };

int main(){
	int idx = 0;
	long long n;
	fibonacci[0] = 0;	fibonacci[1] = 1; // 0번째 피보나치 수를 0, 1번째 피보나치 수를 1로 함
	for (int i = 2; i < 90; i++){fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];} // 89번째 피보나치 수가 K의 최댓값보다 큼
	scanf("%lld", &n);
	if (n == 1){printf("1"); return 0;} // n == 1일 때는 정상적으로 동작하지 않아서 예외로 둠
	while (n > fibonacci[idx]){
		idx++;
	}
	if (n < fibonacci[idx]){idx--;} // 보정
	while (idx > 1){ // 참고로 1이 절대로 연속되어 출력되지 않음
		if (n >= fibonacci[idx]){ // n이 idx번째 피보나치 수보다 작지 않다면
			n -= fibonacci[idx];
			printf("1");
		}
		else { // 작다면
			printf("0");
		}
		idx--;
	}
}