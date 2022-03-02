// 1026 보물
// https://www.acmicpc.net/problem/1026
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num, sum = 0;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> num;
		a.push_back(num);
	}
	for (int n = 0; n < N; n++){
		cin >> num;
		b.push_back(num);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(a.begin(), a.end());
	for (int n = 0; n < N; n++){
		sum += a[n] * b[n];
	}
	cout << sum;
}