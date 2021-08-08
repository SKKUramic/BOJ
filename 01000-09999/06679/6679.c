// 6679 싱기한 네자리 숫자
// https://www.acmicpc.net/problem/6679
#include <stdio.h>

enum BIT {A = 10, B, C, D, E, F};

int compare(int N){
	int ten[5] = {0, };
	int twelve[5] = {0, };
	int sixteen[5] = {0, };
	int temp;
	int ten_len = 0, twelve_len = 0, sixteen_len = 0;
	int ten_sum = 0, twelve_sum = 0, sixteen_sum = 0;
	temp = N;
	while (temp > 0){
		ten[ten_len] = temp % 10;
		temp /= 10;
		ten_len++;
	}
	temp = N;
	while (temp > 0){
		twelve[twelve_len] = temp % 12;
		temp /= 12;
		twelve_len++;
	}
	temp = N;
	while (temp > 0){
		sixteen[sixteen_len] = temp % 16;
		temp /= 16;
		sixteen_len++;
	}
	for (int i = 0; i < ten_len; i++){
		ten_sum += ten[i];
	}
	for (int j = 0; j < twelve_len; j++){
		twelve_sum += twelve[j];
	}
	for (int k = 0; k < sixteen_len; k++){
		sixteen_sum += sixteen[k];
	}
	if (ten_sum == twelve_sum && twelve_sum == sixteen_sum){
		return 1;
	}
	else {
		return 0;
	}
}

int main(){
	for (int a = 1000; a < 10000; a++){
		if (compare(a) == 1){
			printf("%d\n", a);
		}
	}
}