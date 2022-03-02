// 1019 책 페이지
// https://www.acmicpc.net/problem/1019
#include <stdio.h>

long long int answer[10] = {0, };

int main(){
	int N, temp, ten_pow = 1;
	scanf("%d", &N);
	temp = N;
	while (temp > 0){
		if (temp >= 10){
			for (int i = 0; i < 10; i++){
				if (i == 0){
					answer[i] += (temp / 10 - 1) * ten_pow; // 0이 맨 앞에 오는 경우만 제외	ex) 01, 031
					if (temp % 10 == 0){ // 만약 맨 뒷자리가 0이면
						answer[i] += (N % ten_pow + 1); // ??...0...0 ~ ??...0...x (x = N % ten_pow)
					}
					else {
						answer[i] += ten_pow; // ??...0...0 ~ ??...0...9
					}
				}
				else if (i < temp % 10){
					answer[i] += (1 + temp / 10) * ten_pow;
				}
				else if (i > temp % 10){
					answer[i] += (temp / 10) * ten_pow;
				}
				else {
					answer[i] += ((temp / 10) * ten_pow + (N % ten_pow + 1)); 
				}
			}
		}
		else {
			for (int i = 0; i < 10; i++){
				if (i == 0){
					continue; // 최고 자리에는 0이 올 수 없음
				}
				else if (i < temp){
					answer[i] += ten_pow; // i00...0 ~ i99...9
				}
				else if (i > temp){
					break; // 최고 자리의 숫자보다 큰 것이 올 수 없음
				}
				else {
					answer[i] += (1 + N % ten_pow);
				}
			}
		}
		ten_pow *= 10;
		temp /= 10;
	}
	for (int i = 0; i < 10; i++){
		printf("%lld ", answer[i]);
	}
}