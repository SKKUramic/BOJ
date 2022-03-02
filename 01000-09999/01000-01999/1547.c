// 1547 공
// https://www.acmicpc.net/problem/1547
#include <stdio.h>

int cup[4] = {0, };

int main(){
	int shake, c1, c2, temp;
	cup[1] = 1;
	scanf("%d", &shake);
	while (shake-- > 0){
		scanf("%d %d", &c1, &c2);
		temp = cup[c1];
		cup[c1] = cup[c2];
		cup[c2] = temp;
	}
	for (int i = 1; i <= 3; i++){
		if (cup[i] == 1){
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}