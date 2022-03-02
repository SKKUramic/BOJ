// 16435 스네이크버드
// https://www.acmicpc.net/problem/16435
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

int main(){
	int N, Length;
	cin >> N >> Length;
	for (int n = 0; n < N; n++){
		cin >> arr[n];
	}
	sort(arr, arr + N);
	for (int n = 0; n < N; n++){
		if (Length < arr[n]){break;}
		Length++;
	}
	cout << Length;
}