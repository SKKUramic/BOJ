// 5959 Crop Circles
// https://www.acmicpc.net/problem/5959
#include <stdio.h>

int Circle[1000][3] = {0, }; // X_i, Y_i, R_i
int Circle_overlap[1000] = {0, };

int main(){
	int X, Y, R, N, Circle_count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d %d %d", &Circle[i][0], &Circle[i][1], &Circle[i][2]);
		for (int j = 0; j < i; j++){
			X = (Circle[i][0] - Circle[j][0]) * (Circle[i][0] - Circle[j][0]);
			Y = (Circle[i][1] - Circle[j][1]) * (Circle[i][1] - Circle[j][1]);
			R = (Circle[i][2] + Circle[j][2]) * (Circle[i][2] + Circle[j][2]);
			if (X + Y < R){
				Circle_overlap[i]++;
				Circle_overlap[j]++;
			}
		}
		Circle_count++;
	}
	for (int i = 0; i < Circle_count; i++){
		printf("%d\n", Circle_overlap[i]);
	}
}