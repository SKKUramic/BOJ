// 11054 가장 긴 바이토닉 부분 수열
// https://www.acmicpc.net/problem/11054
// 사실상 모든 경우를 뒤져봐야 하는 문제입니다. 어디가 중심점인지 알 수 없으니까요.
#include <iostream>
using namespace std;

int N;
int arr[1001];

int LIS(int idx){
	int min, max = 0;
	int len[1001];
	for (int i = 0; i <= idx; i++){
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
	return max;
}

int LDS(int idx){
	int min, another_max = 0;
	int another_len[1001];
	for (int i = idx; i < N; i++){
		min = 0;
		for (int j = idx; j < i; j++){
			if (arr[i] < arr[j]){
				if (min < another_len[j]){
					min = another_len[j];
				}
			}
		}
		another_len[i] = min + 1;
		if (another_max < another_len[i]){
			another_max = another_len[i];
		}
	}
	return another_max;
}

int LIS_LDS(){
	int MAX = 0;
	for (int i = 0; i < N; i++){
		MAX = max(MAX, LIS(i) + LDS(i));
	}
	return MAX - 1;
}

int main(){	
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	cout << LIS_LDS() << endl;
	return 0;
}