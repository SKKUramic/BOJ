// 2851 슈퍼마리오
// https://www.acmicpc.net/problem/2851
#include <stdio.h>
#include <stdlib.h>

int nearest_100 = 0;
int mushroom[11] = {0, };

void eating_mushroom(int idx, int score){
	if (abs(nearest_100 - 100) > abs(score - 100)){
		nearest_100 = score;
	}
	else if (abs(nearest_100 - 100) == abs(score - 100)){
		if (nearest_100 < score){
			nearest_100 = score;
		}
	}
	else {
		return;
	}
	if (idx == 9){return;}
	eating_mushroom(idx + 1, score + mushroom[idx + 1]);
	return;
}

int main(){
	for (int i = 0; i < 10; i++){
		scanf("%d", &mushroom[i]);
	}
	eating_mushroom(0, mushroom[0]);
	printf("%d", nearest_100);
}