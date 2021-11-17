// 9076 점수 집계
// https://www.acmicpc.net/problem/9076
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<int> v;
	int TC, score;
	cin >> TC;
	for (int i = 0; i < TC; i++){
		for (int k = 0; k < 5; k++){
			cin >> score;
			v.push_back(score);
		}
		sort(v.begin(), v.end());
		if (v[3] - v[1] >= 4){cout << "KIN\n";}
		else {
			cout << v[1] + v[2] + v[3] << '\n';
		}
		v.clear();
	}
}