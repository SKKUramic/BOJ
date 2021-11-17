// 11098 첼시를 도와줘!
// https://www.acmicpc.net/problem/11098
#include <stdio.h>
#include <string.h>

int main(){
	int TC, People, max_cost, cost;
	char name[21], most_name[21];
	scanf("%d", &TC);
	while (TC-- > 0){
		max_cost = -1;
		scanf("%d", &People);
		for (int p = 0; p < People; p++){
			scanf("%d", &cost);
			scanf("%s", name);
			if (cost > max_cost){
				max_cost = cost;
				strcpy(most_name, name);
			}
		}
		printf("%s\n", most_name);
	}
}