// 1546 평균
#include <stdio.h>

int main(/*int argc, char* argv[]*/) {
	double arr[1000];
	int N, temp;
	double score = 0, max = -1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%lf", &arr[i]);
		if (max < arr[i]){
			max = arr[i];
		}
	}
	temp = N;
	while (temp-- > 0){
		score += (arr[temp] / max) * 100.0;
	}
	printf("%lf", score / (double)N);
}