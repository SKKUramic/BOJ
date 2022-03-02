// 8891 점 숫자
// https://www.acmicpc.net/problem/8891
#include <stdio.h>

int main(){
	int A, B, Ax, Ay, Bx, By;
	int TC, x, y, num;
	scanf("%d", &TC);
	while (TC-- > 0){
		Ax = -1; Bx = -1; num = 1;
		scanf("%d %d", &A, &B);
		for (int i = 1; i < 1000; i++){
			for (int j = i; j >= 1; j--){
				if (num == A){
					Ax = i - j + 1;
					Ay = j;
				}
				if (num == B){
					Bx = i - j + 1;
					By = j;
				}
				num++;
			}
			if (Ax != -1 && Bx != -1){break;}
		}
		x = Ax + Bx;
		y = Ay + By;
		num = x + y - 1;
		printf("%d\n", (num * (num + 1) / 2) - (num - x));
	}
}