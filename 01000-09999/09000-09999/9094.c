// 9094 수학적 호기심
// https://www.acmicpc.net/problem/9094
#include <stdio.h>

int main(){
	int TC, n, m, count;
	scanf("%d", &TC);
	while (TC-- > 0){
		scanf("%d %d", &n, &m);
		count = 0;
		for (int a = 1; a < n; a++){
			for (int b = a + 1; b < n; b++){
				if (((a * a + b * b + m) / (a * b)) * (a * b) == (a * a + b * b + m)){
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
}