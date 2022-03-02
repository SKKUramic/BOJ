// 14467 소가 길을 건너간 이유 1
// https://www.acmicpc.net/problem/14467
#include <stdio.h>

int cow[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int main(){
	int answer = 0;
	int N, cownum, position;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d %d", &cownum, &position);
		if (cow[cownum] != -1 && cow[cownum] != position){
			answer++;
		}
		cow[cownum] = position;
	}
	printf("%d", answer);
}