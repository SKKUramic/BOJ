// 17211 좋은 날 싫은 날
#include <stdio.h>
#include <math.h>

int main(){
	int day, emotion; //좋은날 0, 싫은날 1
	double good_good, good_bad, bad_good, bad_bad;
	double N_days_good, N_days_bad, N_days_good_temp;
	scanf("%d %d", &day, &emotion);
	scanf("%lf %lf %lf %lf", &good_good, &good_bad, &bad_good, &bad_bad);
	if (emotion == 0){
		N_days_good = good_good;
		N_days_bad = good_bad;
	}
	else {
		N_days_good = bad_good;
		N_days_bad = bad_bad;
	}
	for (int i = 1; i < day; i++){
		N_days_good_temp = N_days_good;
		//printf("%lf x %lf + %lf x %lf\n", N_days_good, good_good, N_days_bad, bad_good);
		N_days_good = N_days_good * good_good + N_days_bad * bad_good;
		//printf("%lf x %lf + %lf x %lf\n", N_days_bad, bad_bad, N_days_good, good_bad);
		N_days_bad = N_days_bad * bad_bad + N_days_good_temp * good_bad;
		//printf("%lf %lf\n", N_days_good, N_days_bad);
	}
	N_days_good *= 1000;
	N_days_bad *= 1000;
	N_days_good = floor(N_days_good + 0.5);
	N_days_bad = floor(N_days_bad + 0.5);
	printf("%0.lf\n%0.lf", N_days_good, N_days_bad);
}