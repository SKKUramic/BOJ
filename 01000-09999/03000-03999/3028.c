// 3028 창영마을
// https://www.acmicpc.net/problem/3028
#include <stdio.h>

int arr[4] = {0, };

int main(){
	int temp;
	char shake[51];
	arr[1] = 1;
	scanf("%s", shake);
	for (int x = 0; shake[x] != '\0'; x++){
		if (shake[x] == 'A'){
			temp = arr[1];
			arr[1] = arr[2];
			arr[2] = temp;
		}
		else if (shake[x] == 'B'){
			temp = arr[2];
			arr[2] = arr[3];
			arr[3] = temp;
		}
		else if (shake[x] == 'C'){
			temp = arr[1];
			arr[1] = arr[3];
			arr[3] = temp;
		}
	}
	for (int i = 1; i <= 3; i++){
		if (arr[i] == 1){
			printf("%d", i);
			break;
		}
	}
}