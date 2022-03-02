// 7567 그릇
// https://www.acmicpc.net/problem/7567
#include <stdio.h>
#include <string.h>

int main(){
	int len, height = 10;
	char bowl[51];
	scanf("%s", bowl);
	len = strlen(bowl);
	for (int i = 1; i < len; i++){
		if (bowl[i - 1] == bowl[i]){
			height += 5;
		}
		else {
			height += 10;
		}
	}
	printf("%d", height);
}