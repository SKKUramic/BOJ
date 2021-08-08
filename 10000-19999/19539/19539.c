// 19539 사과나무
// https://www.acmicpc.net/problem/19539
#include <stdio.h>
#include <stdbool.h>
#include <clock.h>

int tree[100001] = {0, };

int main(){
	int height_sum = 0, one_sum = 0, two_sum = 0;
	int N, idx;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &tree[i]);
		height_sum += tree[i];
		two_sum += tree[i] / 2;
	}
	if (height_sum % 3 == 0){
		if (two_sum >= height_sum / 3){ // 2만큼 자라는 물뿌리개를 뿌릴 수 있는 일수가 총 일수보다 같거나 클 때
			printf("YES");
		}
		else {
			printf("NO");
		}
	}
	else {
		printf("NO");
	}
	return 0;
}