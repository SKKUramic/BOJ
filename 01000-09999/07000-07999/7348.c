// 7348 테이블 옮기기
// https://www.acmicpc.net/problem/7348
#include <stdio.h>
#include <string.h>

int arr[201];

int main(){
	int TC, Table, minute, a, b;
	scanf("%d", &TC);
	while (TC-- > 0){
		minute = 0;
		for (int i = 0; i <= 200; i++){arr[i] = 0;}
		scanf("%d", &Table);
		for (int t = 0; t < Table; t++){
			scanf("%d %d", &a, &b);
			a--; b--;
			a /= 2; b /= 2;
			if (a > b){
				int tmp = a;
				a = b;
				b = tmp;
			}
			for (int i = a; i <= b; i++){
				arr[i]++;
			}
		}
		for (int i = 0; i <= 200; i++){
			if (minute < arr[i]){minute = arr[i];}
		}
		printf("%d\n", minute * 10);
	}
}