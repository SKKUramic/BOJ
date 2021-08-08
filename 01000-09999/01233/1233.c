// 1233 주사위
// https://www.acmicpc.net/problem/1233
#include <stdio.h>

int count[81] = {0, };
int max = -1;
int max_idx = 0;

int main(){
	int s1, s2, s3;
	scanf("%d %d %d", &s1, &s2, &s3);
	for (int i = 1; i <= s1; i++){
		for (int j = 1; j <= s2; j++){
			for (int k = 1; k <= s3; k++){
				count[i + j + k]++;
			}
		}
	}
	for (int idx = 1; idx <= s1 + s2 + s3; idx++){
		if (max < count[idx]){
			max = count[idx];
			max_idx = idx;
		}
	}
	printf("%d", max_idx);
}