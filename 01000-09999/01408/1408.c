// 1408 24
// https://www.acmicpc.net/problem/1408
#include <stdio.h>

int main(){
	int mission_hour, mission_minute, mission_second, mission_sum;
	int D_hour, D_minute, D_second, D_sum;
	int answer_hour, answer_minute, answer_second, answer_sum;
	scanf("%d:%d:%d", &D_hour, &D_minute, &D_second);
	scanf("%d:%d:%d", &mission_hour, &mission_minute, &mission_second);
	mission_sum = mission_hour * 3600 + mission_minute * 60 + mission_second;
	D_sum = D_hour * 3600 + D_minute * 60 + D_second;
	if (mission_sum > D_sum){
		answer_sum = mission_sum - D_sum;
	}
	else {
		answer_sum = 86400 - (D_sum - mission_sum);
	}
	answer_hour = answer_sum / 3600;
	answer_minute = (answer_sum / 60) % 60;
	answer_second = answer_sum % 60;
	printf("%02d:%02d:%02d", answer_hour, answer_minute, answer_second);
}