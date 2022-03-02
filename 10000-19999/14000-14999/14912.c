// 14912 숫자 빈도수
// https://www.acmicpc.net/problem/14912
#include <stdio.h>

int digit[10] = {0, };

void plus_digit(int n){
	while (n > 0){
		digit[n % 10]++;
		n /= 10;
	}
	return;
}

int main(){
	int N, d;
	scanf("%d %d", &N, &d);
	for (int n = 1; n <= N; n++){
		plus_digit(n);
	}
	printf("%d", digit[d]);
}