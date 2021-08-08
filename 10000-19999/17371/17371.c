// 17371 이사
#include <stdio.h>
#include <math.h>

double point[1001][2];
double min_average = 2000000001;
int answer;

int main(){
	int N;
	double x, y, current_max, current_length;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%lf %lf", &point[i][0], &point[i][1]);
	}
	for (int i = 0; i < N; i++){
		current_max = -1;
		for (int j = 0; j < N; j++){
			current_length = sqrt((point[i][0] - point[j][0]) * (point[i][0] - point[j][0]) + (point[i][1] - point[j][1]) * (point[i][1] - point[j][1]));
			if (current_length > current_max){
				current_max = current_length;
			}
		}
		if (min_average > current_max){
			min_average = current_max;
			answer = i;
		}
	}
	printf("%.12lf %.12lf", point[answer][0], point[answer][1]);
}