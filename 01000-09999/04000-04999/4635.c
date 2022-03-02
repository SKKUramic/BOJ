// 4635 Speed Limit
// https://www.acmicpc.net/problem/4635
#include <stdio.h>

int main(){
	int speed, mile_sum, prev_time, cur_time, n; 
	scanf("%d", &n);
	while (n != -1){
		prev_time = 0;
		mile_sum = 0;
		for (int i = 0; i < n; i++){
			scanf("%d %d", &speed, &cur_time);
			mile_sum += speed * (cur_time - prev_time);
			prev_time = cur_time;
		}
		printf("%d miles\n", mile_sum);
		scanf("%d", &n);
	}
}