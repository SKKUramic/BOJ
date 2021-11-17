// 11931 수 정렬하기 4
// https://www.acmicpc.net/problem/11931
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){return a > b;}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num;
	vector<int> v;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end(), cmp);
	for (int n = 0; n < N; n++){
		cout << v[n] << '\n';
	}
}