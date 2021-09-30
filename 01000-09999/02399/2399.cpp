// 2399 거리의 합
// https://www.acmicpc.net/problem/2399
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long arr[10001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long distance = 0;
	int N;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> arr[n];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			distance += abs(arr[i] - arr[j]);
		}
	}
	cout << distance;
}