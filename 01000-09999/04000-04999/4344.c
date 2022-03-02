// 4344 평균은 넘겠지
#include <stdio.h>

int main(/*int argc, char* argv[]*/) {
	int C, N;
	int score[1000];
	double arg = 0.0, over = 0.0;
	scanf("%d", &C);
	for (int i = 0; i < C; i++){
		scanf("%d", &N);
		for (int j = 0; j < N; j++){
			scanf("%d", &score[j]);
			arg += (double)score[j];
		}
		arg /= (double)N;
		for (int j = 0; j < N; j++){
			if (arg < (double)score[j]){
				over += 1.0;
			}
		}
		printf("%.3lf%%\n", (over / (double)N) * 100.0);
		//printf("arg: %lf, over: %lf\n", arg, over);
		arg = 0.0;
		over = 0.0;
	}
}