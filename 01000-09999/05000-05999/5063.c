// 5063 TGN
// https://www.acmicpc.net/problem/5063
#include <stdio.h>

int main(){
	int tc, nothing, benefit, cost;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++){
		scanf("%d %d %d", &nothing, &benefit, &cost);
		if (nothing > benefit - cost){
			printf("do not advertise\n");
		}
		else if (nothing < benefit - cost){
			printf("advertise\n");
		}
		else {
			printf("does not matter\n");
		}
	}
}