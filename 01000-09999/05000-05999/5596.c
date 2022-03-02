// 5596 시험 점수
// https://www.acmicpc.net/problem/5596
#include <stdio.h>

int main(){
	int minkook_score[4]; int manse_score[4];
	int minkook_sum = 0, manse_sum = 0; 
	for (int i = 0; i < 4; i++){
		scanf("%d", &minkook_score[i]);
		minkook_sum += minkook_score[i];
	}
	for (int i = 0; i < 4; i++){
		scanf("%d", &manse_score[i]);
		manse_sum += manse_score[i];
	}
	if (minkook_sum < manse_sum){
		printf("%d", manse_sum);
	}
	else {
		printf("%d", minkook_sum);
	}
}