// 18110 solved.ac
// https://www.acmicpc.net/problem/18110
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[300001];

int main(){
	int N, exception, average = 0;
	cin >> N;
	if (N == 0){cout << 0; return 0;}
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	sort(arr, arr + N);
	exception = (int)(round((double)(N) * 0.15));
	for (int i = exception; i < N - exception; i++){
		average += arr[i];
	}
	average = (int)(round((double)(average) / (N - 2 * exception)));
	cout << average;
}