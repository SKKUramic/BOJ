// 9461 파도반 수열
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long arr[101];
	int N, T;
	arr[1] = 1; arr[2] = 1; arr[3] = 1; arr[4] = 2; arr[5] = 2;
	for (int k = 6; k < 101; k++) {
		arr[k] = arr[k - 1] + arr[k - 5];
	}
	cin >> T;
	long long* Test = (long long*)malloc(sizeof(long long) * T);
	for (int i = 0; i < T; i++) {
		cin >> N;
		Test[i] = arr[N];
	}
	for (int i = 0; i < T; i++) {
		cout << Test[i] << endl;
	}
	free(Test);
}