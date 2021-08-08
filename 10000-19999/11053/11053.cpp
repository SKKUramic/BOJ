// 11053 가장 긴 증가하는 부분 수열
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, min;
	int arr[1001];
	int len[1001];
	int max = 0;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++){
		min = 0;
		for (int j = 0; j < i; j++){
			if (arr[i] > arr[j]){
				if (min < len[j]){
					min = len[j];
				}
			}
		}
		len[i] = min + 1;
		if (max < len[i]){
			max = len[i];
		}
	}
	cout << max << endl;
	return 0;
}