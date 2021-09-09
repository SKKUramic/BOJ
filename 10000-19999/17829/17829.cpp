// 17829 222-풀링
// https://www.acmicpc.net/problem/17829
#include <iostream>
#include <algorithm>
using namespace std;

short arr[1024][1024];

short Pooling_222(int N, int left_top, int right_bottom){
	short Arr[4];
	if (N == 1){
		Arr[0] = arr[left_top][right_bottom - 1];
		Arr[1] = arr[left_top][right_bottom];
		Arr[2] = arr[left_top + 1][right_bottom - 1];
		Arr[3] = arr[left_top + 1][right_bottom];
	}
	else {
		Arr[0] = Pooling_222(N / 2, left_top, right_bottom - N);
		Arr[1] = Pooling_222(N / 2, left_top, right_bottom);
		Arr[2] = Pooling_222(N / 2, left_top + N, right_bottom - N);
		Arr[3] = Pooling_222(N / 2, left_top + N, right_bottom);
	}
	sort(Arr, Arr + 4);
	return Arr[2];
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	short answer;
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> arr[i][j];
		}
	}
	answer = Pooling_222(N / 2, 0, N - 1);
	cout << answer;
}