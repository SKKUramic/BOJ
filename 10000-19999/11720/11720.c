// 11720 숫자의 합
#include <stdio.h>

int main(){
	char number[100];
	int N, answer = 0;
	scanf("%d", &N);
	scanf("%s", number);
	for (int i = 0; i < N; i++){
		answer += number[i];
	}
	answer -= 48 * N;
	printf("%d", answer);
}