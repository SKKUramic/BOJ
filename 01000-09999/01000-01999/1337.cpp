// 1337 올바른 배열
// https://www.acmicpc.net/problem/1337
// https://mm5-gnap.tistory.com/306
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num, max_stack = 1, stack, diff;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++){
		diff = 0;
		stack = 1;
		for (int j = i + 1; j < N; j++){
			diff += v[j] - v[j - 1];
			if (diff >= 5){break;} // 두 수간의 차의 합이 5 이상이면 종료(최선의 경우라면 4이기 때문)
			stack++;
		}
		if (max_stack < stack){max_stack = stack;}
	}
	cout << 5 - max_stack;
}