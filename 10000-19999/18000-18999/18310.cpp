// 18310 안테나
// https://www.acmicpc.net/problem/18310
// 그냥 중간값을 출력하다니 당신은 양심도 없습니까? 네
#include <iostream>
#include <algorithm>
using namespace std;

int arr[200001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	sort(arr, arr + N);
	if (N % 2 == 1){
		cout << arr[(N - 1) / 2];
	}
	else {
		cout << arr[N / 2 - 1];
	}
}