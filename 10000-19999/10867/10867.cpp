// 10867 중복 빼고 정렬하기
// https://www.acmicpc.net/problem/10867
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool used[2002];
vector<int> v;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> num;
		if (used[num + 1000] == false){
			used[num + 1000] = true;
			v.push_back(num);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << ' ';
	}
}