// 6190 Another Cow Number Game
// https://www.acmicpc.net/problem/6190
#include <stdio.h>

int main(){
	long long N;
	int score = 0;
	scanf("%lld", &N);
	while (N != 1){
		if (N % 2 == 0) {N /= 2;}
		else {N = 3 * N + 1;}
		score++;
	}
	printf("%d", score);
}