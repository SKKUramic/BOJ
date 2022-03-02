// 2991 사나운 개
// https://www.acmicpc.net/problem/2991
#include <stdio.h>

int main(){
	int A, B, C, D;
	int arr[3], cnt[3] = {0, };
	scanf("%d %d %d %d", &A, &B, &C, &D);
	for (int i = 0; i < 3; i++){
		scanf("%d", &arr[i]);
		if (arr[i] % (A + B) <= A && arr[i] % (A + B) != 0){
			cnt[i]++;
		}
		if (arr[i] % (C + D) <= C && arr[i] % (C + D) != 0){
			cnt[i]++;
		}
		printf("%d\n", cnt[i]);
	}
}