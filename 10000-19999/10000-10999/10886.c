// 10886 0 = not cute / 1 = cute
// https://www.acmicpc.net/problem/10886
#include <stdio.h>

int main(){
	int arr[2] = {0, 0};
	int N, num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		arr[num]++;
	}
	if (arr[0] > arr[1]){
		printf("Junhee is not cute!");
	}
	else {
		printf("Junhee is cute!");
	}
}