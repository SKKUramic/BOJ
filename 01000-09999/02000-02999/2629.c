// 2629 양팔저울
// https://www.acmicpc.net/problem/2629
// https://jaimemin.tistory.com/497(꾸준함님의 블로그)에서 dp를 어떻게 쓰면 되는지 배웠습니다
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int weight_count, marble, marble_count;
int weight[31] = {0, };
int can_find[31][15001] = {0, };

void Knapsack(int current_weight_count, int current_weight){ // 지금까지 고려한 추의 수, 현재 잴 수 있는 무게(오른쪽 기준)
	if (current_weight_count > weight_count) {return;} // 이미 모든 추를 고려함
	if (can_find[current_weight_count][current_weight] != -1) {return;} // 이미 이 경우를 고려함
	can_find[current_weight_count][current_weight] = 1;
	Knapsack(current_weight_count + 1, current_weight + weight[current_weight_count]); // 지금의 추를 오른쪽에 추가함
	Knapsack(current_weight_count + 1, current_weight); // 그냥 지금 추를 사용하지 않음
	Knapsack(current_weight_count + 1, abs(current_weight - weight[current_weight_count])); // 지금의 추를 왼쪽에 추가함
	return;
}

int main(){
	scanf("%d", &weight_count);
	memset(can_find, -1, sizeof(can_find));
	for (int i = 0; i < weight_count; i++){
		scanf("%d", &weight[i]);
	}
	Knapsack(0, 0);
	scanf("%d", &marble_count);
	for (int m = 0; m < marble_count; m++){
		scanf("%d", &marble);
		if (marble > 15000) {printf("N ");} // 잴 수 있는 최대 무게를 초과함
		else if (can_find[weight_count][marble] == -1) {printf("N ");} // 잴 수 없는 무게
		else {printf("Y ");} // 잴 수 있는 무게
	}
}