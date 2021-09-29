// 2490 윷놀이
// https://www.acmicpc.net/problem/2490
#include <stdio.h>

int main(){
	int arr[4], one;
	for (int i = 0; i < 3; i++){
		one = 0;
		for (int n = 0; n < 4; n++){
			scanf("%d", &arr[n]);
			if (arr[n] == 1){one++;}
		}
		if (one == 4){printf("E\n");}
		else {
			printf("%c\n", 'A' + (4 - one - 1));
		}
	}
}