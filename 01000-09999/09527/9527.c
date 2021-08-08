// 9527 1의 개수 세기
// https://www.acmicpc.net/problem/9527
#include <stdio.h>

long long one_count[100] = {0, }; // n자리까지의 수를 고려할 때의 1의 개수

int main(){
	long long A_count = 0, B_count = 0, temp, A, B;
	int idx;
	scanf("%lld %lld", &A, &B);
	temp = 1;
	for (int i = 1; i <= 55; i++){
		one_count[i] = 2 * one_count[i - 1] + temp;
		temp *= 2;
	}
	A--; // 1 ~ A-1까지의 수를 제외해야 하므로 A의 값을 1 줄임
	while (A > 0){
		temp = 1; idx = 0;
		while (2 * temp - 1 <= A){
			temp *= 2;
			idx++;
		}
		A_count += one_count[idx]; // temp - 1까지의 1의 개수
		A_count += (A - temp + 1); // temp ~ A의 가장 높은 자릿수에 있는 1의 개수
		A -= temp; // 남은 부분의 1을 세기 위해 A값 조정
	}
	while (B > 0){
		temp = 1; idx = 0;
		while (2 * temp - 1 <= B){
			temp *= 2;
			idx++;
		}
		B_count += one_count[idx];
		B_count += (B - temp + 1);
		B -= temp;
	}
	printf("%lld", B_count - A_count);
}