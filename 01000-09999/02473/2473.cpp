// 2473 세 용액
// https://www.acmicpc.net/problem/2473
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long arr[5001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, left, right;
	int zero_left, zero_middle, zero_right;
	long long sum, min_sum = 9999999999;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> arr[n];
	}
	sort(arr, arr + N);
	for (int middle = 1; middle < N - 1; middle++){
		left = 0; right = N - 1;
		while (left < middle && middle < right){
			sum = arr[left] + arr[middle] + arr[right];
			if (sum == 0){
				zero_left = left;
				zero_middle = middle;
				zero_right = right;
				break;
			}
			if (min_sum > abs(sum)){
				zero_left = left;
				zero_middle = middle;
				zero_right = right;
				min_sum = abs(sum);
			}
			if (sum < 0){left++;}
			else {right--;}
		}
		if (sum == 0){break;}
	}
	cout << arr[zero_left] << ' ' << arr[zero_middle] << ' ' << arr[zero_right];
}