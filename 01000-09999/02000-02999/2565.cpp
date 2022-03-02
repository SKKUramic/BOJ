// 2565 전깃줄
// https://www.acmicpc.net/problem/2565
// LIS 알고리즘을 사용하는 문제입니다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> cable;

int main(){
	int N, L, R, min, max = 0;
	int arr[1001];
	int len[1001];
	cin >> N;
	for (int i = 0; i < N; i++){
		arr[i] = -1; 
	}
	for (int i = 0; i < N; i++){
		cin >> L >> R;
		cable.push_back({L, R});
	}
	sort(cable.begin(), cable.end());
	for (int i = 0; i < N; i++){
		min = 0;
		for (int j = 0; j < i; j++){
			if (cable[i].second > cable[j].second){
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
	cout << N - max << endl;
	return 0;
}