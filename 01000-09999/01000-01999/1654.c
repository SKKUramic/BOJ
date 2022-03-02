// 1654 랜선 자르기
#include <stdio.h>

long long int lan[10001] = {0, };

int main(){
	long long int K, N, line, min_value = 1, max_value = -1, value, count, answer = 0;
	scanf("%lld %lld", &K, &N);
	for (int i = 0; i < K; i++){
		scanf("%lld", &line);
		lan[i] = line;
		if (line > max_value){
			max_value = line;
		}
	}
	//printf("%lld %lld\n", min_value, max_value);
	while (max_value >= min_value){
		count = 0;
		value = (min_value + max_value) / 2;
		//printf("value: %lld\n", value);
		for (int i = 0; i < K; i++){
			count += lan[i] / value;
		}
		if (count >= N){
			if (value > answer){
				answer = value;
			}
			min_value = value + 1;
		}
		else {
			max_value = value - 1;
		}
		//printf("%lld %lld\n", min_value, max_value);
	}
	printf("%lld", answer);
}