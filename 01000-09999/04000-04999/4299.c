// 4299 AFC 윔블던
// https://www.acmicpc.net/problem/4299
#include <stdio.h>

int main(){
	int sum, diff, a, b;
	scanf("%d %d", &sum, &diff);
	a = (sum + diff) / 2;
	b = (sum - diff) / 2;
	if ((sum + diff) % 2 == 1 || (sum - diff) % 2 == 1){
		printf("-1");
	}
	else {
		if (a < 0 || b < 0){
			printf("-1");
		}
		else {
			if (a > b){
				printf("%d %d", a, b);
			}
			else {
				printf("%d %d", b, a);
			}
		}
	}
}