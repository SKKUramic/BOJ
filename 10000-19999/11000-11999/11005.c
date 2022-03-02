// 11005 진법 변환 2
// https://www.acmicpc.net/problem/11005
#include <stdio.h>
#include <string.h>

int main(){
	long long num, B, temp, len;
	char answer[20];
	scanf("%lld %lld", &num, &B);
	for (int i = 0; ; i++){
		if (num == 0){len = i; break;}
		temp = num % B;
		if (temp < 10){
			answer[i] = '0' + temp;
		}
		else {
			answer[i] = 'A' + (temp - 10);
		}
		num /= B;
	}
	for (int i = len - 1; i >= 0; i--){
		printf("%c", answer[i]);
	}
}