// 16462 '나교수' 교수님의 악필
// https://www.acmicpc.net/problem/16462
#include <stdio.h>

int main(){
	int T, score_sum = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		char what[4], c;
		int score = 0;
		scanf("%s", what);
		for (int j = 0; what[j] != '\0'; j++){
			if (what[j] == '0' || what[j] == '6'){what[j] = '9';}
			score = (score * 10) + (what[j] - '0');
		}
		if (score > 100) {score = 100;}
		//printf("score: %d\n", score);
		score_sum += score;
	}
	if (T % 2 == 0){
		printf("%d", score_sum / T + (score_sum % T >= T / 2 ? 1 : 0));
	}
	else {
		printf("%d", score_sum / T + (score_sum % T > T / 2 ? 1 : 0));
	}
}