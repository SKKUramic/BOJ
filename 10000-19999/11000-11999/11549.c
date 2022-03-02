// 11549 Identifying tea
// https://www.acmicpc.net/problem/11549
#include <stdio.h>

int main(){
	int T, num;
	int arr[5] = {0, };
	scanf("%d", &T);
	for (int i = 0; i < 5; i++){
		scanf("%d", &num);
		arr[num]++;
	}
	printf("%d", arr[T]);
}