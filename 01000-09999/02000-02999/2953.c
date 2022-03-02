// 2953 나는 요리사다
// https://www.acmicpc.net/problem/2953
#include <stdio.h>

int main(){
	int maxscore = 0, winner = 0;
	int a1, a2, a3, a4;
	for (int i = 0; i < 5; i++){
		scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
		if (maxscore < a1 + a2 + a3 + a4){
			winner = i + 1;
			maxscore = a1 + a2 + a3 + a4;
		}
	}
	printf("%d %d", winner, maxscore);
}