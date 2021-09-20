// 2847 게임을 만든 동준이
// https://www.acmicpc.net/problem/2847
#include <stdio.h>

int LevelScore[101] = {0, };

int main(){
	int Level, discount = 0, cur_score;
	scanf("%d", &Level);
	for (int i = 0; i < Level; i++){
		scanf("%d", &LevelScore[i]);
	}
	cur_score = LevelScore[Level - 1];
	for (int i = Level - 2; i >= 0; i--){
		if (cur_score <= LevelScore[i]){
			discount += (LevelScore[i] - cur_score + 1);
			cur_score--;
		}
		else {
			cur_score = LevelScore[i];
		}
	}
	printf("%d", discount);
}