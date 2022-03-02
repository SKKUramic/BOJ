// 2774 아름다운 수
// https://www.acmicpc.net/problem/2774
#include <stdio.h>

int idx[10] = {0, };

int main(){
	int TC, N;
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d", &N);
		int beautiful = 0;
		while (N){
			if (idx[N % 10] == 0){
				beautiful++;
			}
			idx[N % 10]++;
			N /= 10;
		}
		printf("%d\n", beautiful);
		for (int i = 0; i < 10; i++){idx[i] = 0;}
	}
}