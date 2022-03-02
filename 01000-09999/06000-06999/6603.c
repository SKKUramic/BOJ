// 6603 로또
// https://www.acmicpc.net/problem/6603
#include <stdio.h>

int len;
int ans_list[6] = {0, };
int arr[20] = {0, };

void LOTTO(int count, int list, int idx){
	if (count == 6){
		int temp = 5;
		while (list > 0){
			ans_list[temp--] = arr[list % 16];
			list /= 16;
		}
		for (int i = 0; i < 6; i++){
			printf("%d ", ans_list[i]);
		}
		printf("\n");
		return;
	}
	for (int i = idx + 1; i <= len; i++){
		LOTTO(count + 1, list * 16 + i, i);
	}
	return;
}

int main(){
	scanf("%d", &len);
	while (len != 0){
		for (int i = 1; i <= len; i++){
			scanf("%d", &arr[i]);
		}
		for (int i = 1; i <= len; i++){
			LOTTO(1, i, i);
		}
		scanf("%d", &len);
		if (len != 0){printf("\n");}
	}
}