// 1449 수리공 항승
// https://www.acmicpc.net/problem/1449
#include <stdio.h>

int broken[2001] = {0, };

int main(){
	int N, L, num, idx = 1, count = 0;
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		broken[num] = 1;
	}
	while (idx <= 1000){
		if (broken[idx] == 1){
			for (int i = idx; i < idx + L; i++){
				broken[i] = 0;
			}
			count++;
		}
		idx++;
	}
	printf("%d", count);
}