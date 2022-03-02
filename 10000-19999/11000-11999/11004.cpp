// 11004 K번째 수
// https://www.acmicpc.net/problem/11004
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, num;
	vector<int> v;
	cin >> N >> K;
	for (int n = 0; n < N; n++){
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cout << v[K - 1];
}