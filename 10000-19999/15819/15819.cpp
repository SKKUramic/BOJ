// 15819 너의 핸들은
// https://www.acmicpc.net/problem/15819
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> S;
	string K;
	int N, idx;
	cin >> N >> idx;
	for (int i = 0; i < N; i++){
		cin >> K;
		S.push_back(K);
	}
	sort(S.begin(), S.end());
	cout << S[idx - 1];
}