// 1362 펫
// https://www.acmicpc.net/problem/1362
#include <stdio.h>

int main(){
	char command = '?';
	int good_weight = 1, now_weight = 1, command_num = 1;
	int is_dead = 0, time = 0;
	scanf("%d %d", &good_weight, &now_weight);
	while (good_weight != 0 || now_weight != 0){
		time++;
		is_dead = 0;
		scanf("%c %d", &command, &command_num);
		while (command != '#' || command_num != 0){
			if (command == 'E'){
				now_weight -= command_num;
			}
			else if (command == 'F'){
				now_weight += command_num;
			}
			if (now_weight <= 0){is_dead = 1;}
			scanf("%c %d", &command, &command_num);
		}
		printf("%d ", time);
		if (is_dead == 1){printf("RIP\n");}
		else if (good_weight / 2 < now_weight && now_weight < 2 * good_weight){
			printf(":-)\n");
		}
		else {
			printf(":-(\n");
		}
		scanf("%d %d", &good_weight, &now_weight);
	}
}