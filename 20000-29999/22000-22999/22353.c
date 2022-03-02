// 22353 헤이카카오
// https://www.acmicpc.net/problem/22353
// 부동 소수점 예외를 조심하십시오
#include <stdio.h>

double removing(double x){
	double temp = x;
	while (temp >= 1.0000000000000000){
		temp -= 1.0000000000000000;
	}
	return x - temp;
}

int main(){
	double possibility, first_possibility, correction, time, current_time, answer, possibility_accumulate;
	answer = 0.000000000000000;
	current_time = 0.000000000000000;
	scanf("%lf %lf %lf", &time, &possibility, &correction);
	// 부동 소수점의 보정값을 없애는 과정
	time = removing(time);
	possibility = removing(possibility);
	correction = removing(correction);
	
	possibility /= 100;
	correction /= 100;
	correction += 1.000000000000000;
	first_possibility = possibility;
	possibility_accumulate = 1.000000000000000;
	while (1){
		current_time += time;
		if (possibility >= 0.999999999999999){
			answer += current_time * possibility_accumulate;
			break;
		}
		else {
			answer += current_time * possibility_accumulate * possibility;
		}
		possibility_accumulate *= (1.000000000000000 - possibility);
		possibility *= correction;
	}
	printf("%.15lf", answer);
}