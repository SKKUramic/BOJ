// 1173 운동
// https://www.acmicpc.net/problem/1173
#include <stdio.h>

int main(){
	int N, minimum, Maximum, T, Reduce;
	int exercise = 0, current_heartbeat, time = 0;
	scanf("%d %d %d %d %d", &N, &minimum, &Maximum, &T, &Reduce);
	if (minimum + T > Maximum){
		printf("-1");
		return 0;
	}
	current_heartbeat = minimum;
	while (exercise != N){
		if (current_heartbeat + T <= Maximum){
			exercise++;
			current_heartbeat += T;
		}
		else {
			current_heartbeat -= Reduce;
			if (current_heartbeat < minimum){current_heartbeat = minimum;}
		}
		time++;
	}
	printf("%d", time);
}