// 5354 J박스
// https://www.acmicpc.net/problem/5354
#include <stdio.h>

int main(){
	int N, J;
	scanf("%d", &N);
	for (int n = 1; n <= N; n++){
		scanf("%d", &J);
		for (int i = 1; i <= J; i++){
			for (int j = 1; j <= J; j++){
				if (i == 1 || i == J || j == 1 || j == J){
					printf("#");
				}
				else {
					printf("J");
				}
			}
			printf("\n");
		}
		if (n != N){printf("\n");}
	}
}