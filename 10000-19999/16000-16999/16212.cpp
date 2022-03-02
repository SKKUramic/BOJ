// 16212 정열적인 정렬
// https://www.acmicpc.net/problem/16212
#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];

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
		cout << arr[n] << ' ';
	}
}