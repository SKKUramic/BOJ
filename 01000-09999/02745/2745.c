// 2745 진법 변환
// https://www.acmicpc.net/problem/2745
#include <stdio.h>
#include <string.h>

int main(){
	long long answer = 0, B, TIME = 1;
	char number[100];
	scanf("%s %lld", number, &B);
	for (int i = strlen(number) - 1; i >= 0; i--){
		if ('0' <= number[i] && number[i] <= '9'){
			answer += TIME * (number[i] - '0');
		}
		else {
			answer += TIME * (number[i] - 'A' + 10);
		}
		TIME *= B;
	}
	printf("%lld", answer);
}