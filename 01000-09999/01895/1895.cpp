// 1895 필터
// https://www.acmicpc.net/problem/1895
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[41][41];

int Filtering(int r, int c){
	vector<int> filter;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			filter.push_back(arr[r + i][c + j]);
		}
	}
	sort(filter.begin(), filter.end());
	return filter[4];
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int R, C, T, filtered, cnt = 0;
	cin >> R >> C;
	for (int r = 0; r < R; r++){
		for (int c = 0; c < C; c++){
			cin >> arr[r][c];
		}
	}
	cin >> T;
	for (int r = 0; r < R - 2; r++){
		for (int c = 0; c < C - 2; c++){
			filtered = Filtering(r, c);
			if (filtered >= T){cnt++;}
		}
	}
	cout << cnt;
}