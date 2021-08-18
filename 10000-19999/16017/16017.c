// 16017 Telemarketer or not?
// https://www.acmicpc.net/problem/16017
#include <stdio.h>

int main(){
	int arr[4];
	for (int i = 0; i < 4; i++){
		scanf("%d", &arr[i]);
	}
	if (arr[0] >= 8 && arr[1] == arr[2] && arr[3] >= 8){
		printf("ignore");
	}
	else {
		printf("answer");
	}
}