// 10807 개수 세기
// https://www.acmicpc.net/problem/10807
#include <stdio.h>

int arr[203] = {0, };

int main(){
	int N, num;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d", &num);
		arr[num + 100]++;
	}
	scanf("%d", &N);
	printf("%d", arr[N + 100]);
}