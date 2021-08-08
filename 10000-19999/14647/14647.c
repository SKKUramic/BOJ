// 14647 준오는 조류혐오야!!
// https://www.acmicpc.net/problem/14647
#include <stdio.h>

int row[501] = {0, };
int col[501] = {0, };
int nine_count = 0;
int row_idx, row_max = -1;
int col_idx, col_max = -1;

int main(){
	int N, M, num;
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			scanf("%d", &num);
			while (num > 0){
				if (num % 10 == 9){
					nine_count++;
					row[n]++;
					col[m]++;
				}
				num /= 10;
			}
		}
	}
	for (int n = 0; n < N; n++){
		if (row_max < row[n]){
			row_max = row[n];
			row_idx = n;
		}
	}
	for (int m = 0; m < M; m++){
		if (col_max < col[m]){
			col_max = col[m];
			col_idx = m;
		}
	}
	if (col_max > row_max){
		printf("%d", nine_count - col_max);
	}
	else {
		printf("%d", nine_count - row_max);
	}
}