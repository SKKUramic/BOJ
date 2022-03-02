// 2822 점수 계산
// https://www.acmicpc.net/problem/2822
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, int> arr[8];

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	int score = 0;
	for (int i = 0; i < 8; i++){
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr, arr + 8);
	for (int i = 3; i < 8; i++){
		score += arr[i].first;
	}
	cout << score << '\n';
	sort(arr + 3, arr + 8, cmp);
	for (int i = 3; i < 8; i++){
		cout << arr[i].second << ' ';
	}
}