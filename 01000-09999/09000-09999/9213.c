// 9213 꽤 좋은 수
// https://www.acmicpc.net/problem/9213
// 에라토스테네스의 체로 그냥 다 구해버리고 푼다.
#include <stdio.h>

int arr[1000001] = {0, };

void init(){
	int idx;
	for (int i = 1; i <= 500000; i++){
		idx = 2 * i;
		for (int j = idx; j <= 1000000; j += i){
			arr[j] += i;
		}
	}
	return;
}

int main(){
	int start, end, badness, test = 0, count = 0, sum;
	init();
	scanf("%d %d %d", &start, &end, &badness);
	while (start != 0 || end != 0 || badness != 0){
		test++;
		count = 0;
		for (int i = start; i <= end; i++){
			if (i - badness <= arr[i] && arr[i] <= i + badness){
				count++;
			}
		}
		printf("Test %d: %d\n", test, count);
		scanf("%d %d %d", &start, &end, &badness);
	}
}