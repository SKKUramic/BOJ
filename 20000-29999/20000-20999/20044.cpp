// 20044 Project Teams
// https://www.acmicpc.net/problem/20044
#include <iostream>
#include <algorithm>
using namespace std;

long long Students[100001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, min = 9999999;
	cin >> N;
	for (int n = 0; n < 2 * N; n++){
		cin >> Students[n];
	}
	sort(Students, Students + 2 * N);
	for (int n = 0; n < N; n++){
		if (min > Students[n] + Students[2 * N - 1 - n]){
			min = Students[n] + Students[2 * N - 1 - n];
		}
	}
	cout << min;
}