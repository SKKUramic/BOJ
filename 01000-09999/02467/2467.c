// 2467 용액
// https://www.acmicpc.net/problem/2467
#include <stdio.h>
#include <stdlib.h>

long long arr[100001] = {0, };

int main(){
	int N, left, right, sum;
	int zero_left, zero_right;
	long long min_sum;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%lld", &arr[n]);
	}
	left = 0; right = N - 1;
	min_sum = 9999999999;
	while (left < right){
		sum = arr[left] + arr[right];
		if (sum == 0){
			zero_left = left;
			zero_right = right;
			break;
		}
		if (min_sum > abs(sum)){
			zero_left = left;
			zero_right = right;
			min_sum = abs(sum);
		}
		if (sum < 0){
			left++;
		}
		else {
			right--;
		}
	}
	printf("%lld %lld", arr[zero_left], arr[zero_right]);
}