// 15688 수 정렬하기 5
// https://www.acmicpc.net/problem/15688
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> arr[n];
	}
	sort(arr, arr + N);
	for (int n = 0; n < N; n++){
		cout << arr[n] << '\n';
	}
}